#include<stdio.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void nhap_int(int arr[], int size)
{
    printf("---------------\r\n");
    for (int i = 0; i < size; i++)
    {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\r\n---------------\r\n");
}
void xuat_int(int arr[], int size)
{
    printf("--------------------\r\n ");
    for(int i = 0; i < size; i++ )
    {
        printf("%d ", arr[i]);
    }
    printf("\r\n-----------------------------\r\n");
}
void nhap_fl(float arr[], int size)
{
    printf("---------------\r\n");
    for (int i = 0; i < size; i++)
    {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%f", &arr[i]);
    }
    // printf("\r\n---------------\r\n");
}
void xuat_fl(float arr[], int size)
{
    printf("--------------------\r\n ");
    for(int i = 0; i < size; i++ )
    {
        printf("%.2f ", arr[i]);
    }
    printf("\r\n-----------------------------\r\n");
}
void copy_int(int arr1[], int arr_cpy[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr_cpy[i] = arr1[i];
    }
}
void copy_fl(float arr1[], float arr_cpy[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr_cpy[i] = arr1[i];
    }
}

void loc_mang_int(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            int temp = j;
            if(arr[i] == arr[j]){
                for(int k = 0; k < size - j; k++)
                {
                    arr[temp] = arr[temp + 1];
                    temp++;
                }
                arr[size] = 0;
                size--;
                j--;
            }
        }
    } 
}
void loc_mang_fl(float arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            int temp = j;
            if(arr[i] == arr[j]){
                for(int k = 0; k < size - j; k++)
                {
                    arr[temp] = arr[temp + 1];
                    temp++;
                }
                arr[size] = 0;
                size--;
                j--;
            }
        }
    } 
}

void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap_fl(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void tangDan_int(int arr[], int size)
{
    for (int  i = 0; i < size; i++)
    {
        for (int j = i; j < size ; j++)
        {
            if(arr[i] > arr[j])
            {
                swap_int(&arr[i], &arr[j]);
            }   
        }  
    }
}

void giamDan_fl(float arr[], int size)
{
    for (int  i = 0; i < size; i++)
    {
        for (int j = i; j < size ; j++)
        {
            if(arr[i] < arr[j])
            {
                swap_fl(&arr[i], &arr[j]);
            }   
        }
    }
}

int main()
{
    // int arr_int[] = {6,6,6,5,9,3,2,7,6,4,10,15,12,2,5,5,9};
    int arr_int_cpy[20] = {0}; 
    int arr_int[10] = {0};
    
    printf("Nhap mang int: \r\n");
    nhap_int(arr_int,SIZE(arr_int));

    printf("Mang int vua nhap la: \r\n");
    xuat_int(arr_int,SIZE(arr_int));
    printf("Mang sau khi dc sap sep tang dan la: \r\n");
    tangDan_int(arr_int, SIZE(arr_int));
    xuat_int(arr_int,SIZE(arr_int));

    copy_int(arr_int, arr_int_cpy, SIZE(arr_int));

    // printf("Mang sau khi loc: \r\n");
    loc_mang_int(arr_int_cpy, SIZE(arr_int));
    // xuat_int(arr_int_cpy, SIZE(arr_int));
    
    int n;
    printf("Nhap so thu n: ");
    scanf("%d", &n);
    printf("Phan tu be thu %d trong mang int vua nhap la: %d \r\n\n", n, arr_int_cpy[n-1]);

    // float arr_fl[] = {1.1, 9.6, 5.5, 6.4, 7.3, 2.4, 9.1, 9.1, 5.5, 6.4};
    float arr_fl_cpy[20] = {0};
    float arr_fl[10] = {0};

    printf("Nhap mang float: \r\n");
    nhap_fl(arr_fl, SIZE(arr_fl));

    printf("Mang float vua dc nhap la: \r\n");
    xuat_fl(arr_fl, SIZE(arr_fl));

    printf("Mang sau khi dc sap xep giam dan la: \r\n");
    giamDan_fl(arr_fl,SIZE(arr_fl));
    xuat_fl(arr_fl, SIZE(arr_fl));

    copy_fl(arr_fl, arr_fl_cpy, SIZE(arr_fl));
    // printf("mang dc copy la \r\n");
    // xuat_fl(arr_fl_cpy, SIZE(arr_fl));

    // printf("mang dc loc la: \r\n");
    loc_mang_fl(arr_fl_cpy,SIZE(arr_fl));
    // xuat_fl(arr_fl_cpy, SIZE(arr_fl));    

    int n1;
    printf("Nhap so thu n1: ");
    scanf("%d", &n1);
    printf("Phan tu lon thu %d trong mang float la: %.2f \r\n", n1, arr_fl_cpy[n1-1]);

    return 0;
}


