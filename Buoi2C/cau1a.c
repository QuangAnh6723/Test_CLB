#include<stdio.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void nhap(int arr[], int size)
{
    printf("\r\n---------------\r\n");
    for (int i = 0; i < size; i++)
    {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\r\n---------------\r\n");
}

void xuat(int arr[], int size)
{
    printf("--------------------\r\n ");
    for(int i = 0; i < size; i++ )
    {
        printf("%d ", arr[i]);
    }
    printf("\r\n-----------------------------\r\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tangDan(int arr[], int size)
{
    for (int  i = 0; i < size; i++)
    {
        for (int j = i; j < size ; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }   
        }
        
    }
    
}

int main()
{
    int a[10] = {0};
    nhap(a, SIZE(a));
    // int a[] = {10, 10, 10, 9, 8, 6, 15, 20, 30, 26, 1, 6 , 7};
    printf("Mang chua duoc sap xep la: \r\n");
    xuat(a, SIZE(a));
    printf("Mang da dc sap xep tang dan la: \r\n");
    tangDan(a, SIZE(a));
    xuat(a, SIZE(a));
    
    return 0;
}


