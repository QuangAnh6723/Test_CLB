//chân ST_CP của 74HC595
#define latchPin  12
//chân SH_CP của 74HC595
#define clockPin  13
//Chân DS của 74HC595
#define data_0_Pin  11
#define data_2_Pin  9

#define button_2  2
#define button_3  3

int sau = 0b1;
int yc1_led = 0;
int yc2_led = 0;
int yc3_led = 0;

int cnt3 = 0;
int cnt2 = 0;

void ngat_yc2()
{
  cnt2++;
  sau|= (1<< cnt2);
  if(sau == 0xff)
  {
    cnt2 = 0;
    sau = 0b1;
  }
}

void ngat_yc3()
{
  cnt3++;
  if (cnt3 > 2)
  {
    cnt3 = 0;
  }
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(data_0_Pin, OUTPUT);
  pinMode(data_2_Pin, OUTPUT);

  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);

  attachInterrupt(1, ngat_yc3, LOW); 
  attachInterrupt(0, ngat_yc2, LOW); 

}

void loop() { 
  
  if(cnt3 == 1)
  {
    led_sangdan();
    LED_OFF(data_2_Pin,100);
  }
  else if(cnt3 == 2)
  {
    led_sangdon();
    LED_OFF(data_2_Pin,100);
  }
  else
  {
    yeucau1();
  }
  
}

void yeucau1()
{
  // con sau bo 
  for (int i = 0; i < 8; i++) {
    yc1_led |= (sau << i);
    digitalWrite(latchPin, LOW);
    shiftOut(data_2_Pin, clockPin, MSBFIRST, yc1_led);  
    digitalWrite(latchPin, HIGH);
    yc1_led = 0;
    delay(200);
    LED_OFF(data_2_Pin,200);
  }
}

void LED_OFF(int dataPin, int timeout)
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0);  
    digitalWrite(latchPin, HIGH);
    delay(timeout);
}

void led_sangdon()     // sang don tu phai sang trai OK
{
  int stateLed_1 = 0;
  int stateLed_2 = 0;
  int cnt = 7;
  for(int j = 0; j <= cnt2; j++)
  {
    for(int i = 0; i <= cnt; i++)
    {
      stateLed_1 = (stateLed_2 | (1 << i));
      digitalWrite(latchPin, LOW);
      shiftOut(data_2_Pin, clockPin, MSBFIRST, stateLed_1);  
      digitalWrite(latchPin, HIGH);
      delay(200);
    }

    stateLed_2 |= 1 << (cnt--);
    digitalWrite(latchPin, LOW);
    shiftOut(data_2_Pin, clockPin, MSBFIRST, stateLed_2);  
    digitalWrite(latchPin, HIGH);
    delay(200);
  }
}

void led_sangdan()    // sang dan tu trai sang phai
{
  int ledState = 0;
  for(int i = 7; i >= 0; i--)
  {
    ledState |= (1 << i);
    digitalWrite(latchPin, LOW);
    shiftOut(data_2_Pin, clockPin, MSBFIRST, ledState);  
    digitalWrite(latchPin, HIGH);
    delay(200);
  }
}


