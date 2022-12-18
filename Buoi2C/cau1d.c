#include<stdio.h>
#include<math.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))


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

float tinhTich(float arr[], int size)
{
    float tich = 1;
    for(int i = 0; i < size; i++)
    {
        tich = tich * arr[i];
    }
    return tich;
}
float tim_min(float arr[], int size)
{
    float min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

void thaypt(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] < 0) {
            arr[i] = fabs(arr[i]);
        }
    }
    
}

int main()
{

    // float a[] = {1.2, 5.6, 9.3, 4.5, 2.3, 6.7, 8.9, 10.5, 16.9, 20.1, 100, 9.3, 9.3, 6.7};
    // float a[] = {3.3,4.4,9.9, 5.5, -8.9, 11.1};
    float a[5] = {0};
    printf("Nhap mang float: \r\n");
    nhap_fl(a, SIZE(a));
    printf("Mang vua nhap la: \r\n");
    xuat_fl(a, SIZE(a));
    float tich = tinhTich(a,SIZE(a));
    printf("Tich cac phan tu cua mang la: %.2f \r\n", tich);
    if(tich > 0)
    {
        printf("So nho nhat trong mang la: %.2f \r\n", tim_min(a, SIZE(a)));
    }
    else if (tich < 0)
    {
        thaypt(a, SIZE(a));
        printf("Mang sau khi da dc thay la: \r\n");
        xuat_fl(a, SIZE(a));  
    }

    return 0;
}

