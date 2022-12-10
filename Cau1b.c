#include<stdio.h>

int main()
{
    int arr[10] = {0};
    int x = 0;
    printf("Ban muon bang cuu chuong may: ");
    scanf("%d", &x);

    printf("Bang cuu chuong nhan %d \r\n", x);
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        arr[i] = (i+1)*x;
        printf(" %d x %d = %d \r\n", i+1, x, arr[i]);
    }
    i = 0;
    printf("Bang cuu chuong chia %d \r\n", x);
    do{

        printf(" %d : %d = %d \r\n", arr[i], x, arr[i] / x);
        i++;
    } while(i < 10);

    return 0;
}