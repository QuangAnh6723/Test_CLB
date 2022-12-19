#include<stdio.h>

void xuat_matrix(int matrix[][2], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %2d", matrix[i][j]);
        }  
        printf("\r\n");
    }
}

void nhap(int matrix[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
}
int Tong(int arr[2][2], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {   
        for(int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int det_2x2(int arr[2][2])
{
    return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
}

int main()
{ 
    // int maX[2][2] = {4,2,3,9};
    int maX[2][2] = {0};
    printf("\nNhap ma tran 2x2: \r\n");
    nhap(maX);
    printf("ma tran vua nhap la: \r\n"); 
    xuat_matrix(maX, 2, 2);
    printf("Tong cac phan tu trong mang la: %d \r\n", Tong(maX,2,2));
    printf("Tinh dinh thuc det = %d \r\n", det_2x2(maX));

    return 0;
}