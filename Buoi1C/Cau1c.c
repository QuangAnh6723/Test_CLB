#include<stdio.h>

int main()
{
    int high = 10;
    printf("Nhap chieu cao than cay: ");
    scanf("%d", &high);
    // printf("Nhap chieu cao than cay: %d \r\n", high);
    int than = high/5;

    for(int i =0; i < high; i++)
    {
        for(int j = 0; j < high - i; j++)
        {
            printf(" ");
        }

        for(int j = 0; j < (i*2)+1 ; j++)
        {
            printf("*");
        }
        printf("\r\n");
    }

    for (int  i = 0; i < than; i++)
    {
        for(int j = 0; j < high; j++)
        {
            printf(" ");
        }
        printf("*\r\n");
    }
    
    return 0;
}




