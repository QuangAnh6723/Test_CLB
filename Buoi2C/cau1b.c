#include<stdio.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void nhap(float arr[], int size)
{
    printf("\r\n---------------\r\n");
    for (int i = 0; i < size; i++)
    {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%f", &arr[i]);
    }
    // printf("\r\n---------------\r\n");
}

void xuat(float arr[], int size)
{
    printf("--------------------\r\n ");
    for(int i = 0; i < size; i++ )
    {
        printf("%.2f ", arr[i]);
    }
    printf("\r\n-----------------------------\r\n");
}

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void giamDan(float arr[], float size)
{
    for (int  i = 0; i < size; i++)
    {
        for (int j = i; j < size ; j++)
        {
            if(arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
            }   
        }
        
    }
}

int main()
{
    float a[10] = {0};
    // float a[] = {1.2, 5.6, 9.3, 4.5, 2.3, 6.7, 8.9, 10.5, 16.9, 20.1, 100, 9.3, 9.3, 6.7};
    printf("Nhap mang float: \r\n");
    nhap(a, SIZE(a));
    printf("Mang chua duoc sap xep\r\n");
    xuat(a, SIZE(a));
    printf("Mang da duoc sap xep giam dan\r\n");
    giamDan(a, SIZE(a));
    xuat(a, SIZE(a));

    return 0;
}

