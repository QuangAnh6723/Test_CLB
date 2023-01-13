#include <LiquidCrystal.h>

int v1, v2,v3;
int led[] = {2,3,4,5,6,7};
int led_sang = 1;
char *trangThai;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void LED_OFF()
{
  for(int i = 0; i < 6; i++)
  {
    digitalWrite(led[i], 0);
  }
}

void TruyenStateLed(char stateLed)
{
  char led_state[8] = {0};
  for(int i = 0; i < 6; i++)
  {
    led_state[i] = (stateLed >> i) & 1; 
  }
  
  for(int i = 0; i < 6; i++)
  {
    digitalWrite(led[i], led_state[i]);
  }
}

void setup() {
  for(int i = 0; i< 6; i++)
  {
    pinMode(led[i], OUTPUT);
  }
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {
  cau1();
  delay(1000);
  LED_OFF();
  cau2();
  LED_OFF();
  cau3();
  delay(1000);
}

void cau1()
{
  int a = analogRead(A0);
  v1 = (5.0 / 1023) * a;
  if(v1 > 0 && v1 <= 1)
  {
    led_sang = 2;
  }
  else if(v1 > 1 && v1 <= 2)
  {
    led_sang = 3;
  }
  else if( v1 <= 3)
  {
    led_sang = 4;
  }
  else if(v1 <=4)
  {
    led_sang = 5;
  }
  else if(v1 <= 5)
  {
    led_sang = 6;
  }
  if(v1 == 0)
  {
    led_sang =1;
  }
  LED_OFF();
  delay(100);
  for(int i = 0; i < led_sang; i++)
  {
    digitalWrite(led[i], HIGH);
  }
}

void cau2()
{
  int a = analogRead(A1);
  v1 = (5.0 / 1023) * a;
  if(v1 > 0 && v1 <= 1)
  {
    sangDan();      // sang dan tu trai sang phai va nguoc lai
    trangThai = "sang dan";
  }
  else if(v1 > 1 && v1 <= 2)
  {
    sangDuoi();     // sang đuổi từ trái sang phải và ngược lại
    trangThai = "Sang duoi";
  }
  else if(v1 <= 3)
  {
    sangDon();      // sáng dồn từ trái sang phải và ngược lại
    trangThai = "Sang don";
  }
  else if(v1 <=4)
  {
    sangNhapNhay();
    trangThai = "nhap nhay";

  }
  else if(v1 <= 5)
  {
    sangXenke();
    trangThai = "Xen ke";
  }
  LED_OFF();
  delay(100);
}

void sangDan()
{
  // sang tu trai sang phai xong nguoc lai
  char stateLed = 0;
  for(int i = 0; i < 6; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(250);
  }
  LED_OFF();
  delay(100);
  for(int i = 5; i >= 0; i--)
  {
    digitalWrite(led[i], HIGH);
    delay(250);
  }
  LED_OFF();
}

void sangDuoi()
{
  for(int i = 0; i < 6; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(250);
    digitalWrite(led[i], LOW);
  }
  for(int i = 5; i >= 0; i--)
  {
    digitalWrite(led[i], HIGH);
    delay(250);
    digitalWrite(led[i], LOW);
  }
}

void sangDon()
{
  // sang don tu trai sang phai 
  char state1 = 0, state2 = 0;
  int cnt = 5;
  
  for(int j = 0; j < 6; j++)
  {
    for(int i = 0; i <= cnt; i++)
    {
      state1 = state2 | (1<<i); 
      TruyenStateLed(state1);
      delay(250);
    }
    state2 |= (1 << cnt--);
    TruyenStateLed(state2);
    delay(250);
  }
  // sang don tu phai sang trai
  state1 = 0; state2 = 0; cnt = 5;
  for(int j = 0; j < 6; j++)
  {
    for(int i = cnt; i > j; i--)
    {
      state1 = state2 | (1 << i); 
      TruyenStateLed(state1);
      delay(250);
    }
    state2 |= (1 << j);
    TruyenStateLed(state2);
    delay(250);
  }
}

void sangNhapNhay()
{
  for(int i = 0; i < 6; i++)
  {
    digitalWrite(led[i], HIGH);
  }
  delay(250);
  LED_OFF();
  delay(250);
}

void sangXenke()
{
  for(int i = 0; i < 6; i++)
  {
    if(i %2 == 0) digitalWrite(led[i],HIGH);
  }
  delay(250);
  LED_OFF();
  for(int i = 0; i < 6; i++)
  {
    if(i %2 != 0) digitalWrite(led[i],HIGH);
  }
  delay(250);
  LED_OFF();
}

void cau3()
{
  int a = analogRead(A2);
  v3 = a*(5.0/1023);
  if(v3 > 0 && v3 <=2.5){
    lcd.setCursor(0,0);
    lcd.print("so led: ");
    lcd.setCursor(9, 0);
    lcd.print(led_sang);  
    lcd.setCursor(0,1);
    lcd.print("TT: ");  
    lcd.setCursor(5,1);
    lcd.print(trangThai);
    trangThai = "";     // xoa trang thai
  } 
  else if(v3 <= 5)
  {
    Serial.print("so led sang: ");
    Serial.println(led_sang);
    Serial.print("TT: ");
    Serial.println(trangThai);
    trangThai = "";
  }
}






