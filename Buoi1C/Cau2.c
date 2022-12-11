#include<stdio.h>

#define T_500k  500000
#define T_200k  200000
#define T_100k  100000
#define T_50k   50000

#define MONEY   4886000

int main()
{
    unsigned long tien = MONEY;
    printf("Nhap so tien: ");
    scanf("%ld", &tien);
    
    int namTram = (int)tien / T_500k;
    tien = tien % T_500k;
    int haiTram = (int)tien / T_200k;
    tien = tien % T_200k;
    int motTram = (int)tien / T_100k;
    tien = tien % T_100k;
    int namMuoi = (int)tien/ T_50k;
    tien = tien % T_50k;

    printf("Tong cac to menh gia: \r\n");
    printf(" %d to 500 000\r\n", namTram);
    printf(" %d to 200 000\r\n", haiTram);
    printf(" %d to 100 000\r\n", motTram);
    printf(" %d to  50 000\r\n", namMuoi);
    printf(" %ld tien du \r\n", tien);

    return 0;
}



