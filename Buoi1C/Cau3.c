#include<stdio.h>

#define doomsday_year 1900

int day = 2;
int nam = 2022;
int ngay = 15;
int thang = 0;

int tim_doomsday(int year)
{
    int a, b, c, d, e;
    int kc = year - doomsday_year;
    a = kc / 12;
    b = kc % 12;
    c = b / 4;
    d = a + b + c;
    e = d % 7;
    // printf(" %d \r\n", e);
    if (e > 4) {
        e = e - 4;
        // printf(" %d \r\n", e);
        day = e - 1;
        // printf(" %d \r\n", day);
    }
    else
    {
        day = day + e;
    } 
    return day;
}

void print_day(int year)
{
    printf("\r\n\t\t Doomsday cua nam %d la ", year);
    switch (day)
    {
    case 0:
        printf("Thu 2\r\n");
        break;
    case 1:
        printf("Thu 3\r\n");
        break;
    case 2:
        printf("Thu 4\r\n");
        break;
    case 3:
        printf("Thu 5\r\n");
        break;
    case 4:
        printf("Thu 6\r\n");
        break;
    case 5:
        printf("Thu 7\r\n");
        break;
    case 6:
        printf("Chu Nhat\r\n");
        break;

    default:
        break;
    }
}

void tim_ngay()
{
    switch (thang)
    {
    case 1:

        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    case 8:
        
        break;
    case 9:
        
        break;
    case 10:
        
        break;
    case 11:
        
        break;
    case 12:
        
        break;
    default:
        break;
    }

}


int main()
{
    
    print_day(nam);
    check_ngay(4);
    
    
    return 0;

}


