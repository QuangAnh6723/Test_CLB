#include<stdio.h>
#include<stdlib.h>

void matrix_init_rand(int matrix[][5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand()%5;
        }  
    }
}

void matrix_init_le(int matrix[][5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = 2 * (rand() % 10) + 1;
        }  
    }
}

void matrix_init_chan(int matrix[][5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = 2 * (rand() % 10);
        }  
    }
}

void xuat_matrix(int matrix[][5], int col, int row)
{
    printf("---------------------\r\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %2d", matrix[i][j]);
        }  
        printf("\r\n");
    }
}

int tim_so_chan_dau_tien(int matrix[][5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(matrix[i][j] % 2 == 0)
            {
                return matrix[i][j];
            }
        }  
    }
    return -1;
}

int tim_so_le_dau_tien(int matrix[][5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(matrix[i][j] % 2 != 0)
            {
                return matrix[i][j];
            }
        }  
    }
    return -1;
}

int main()
{
    int matrix[5][5] = {0}; 
    // matrix_init_rand(matrix, 5, 5);
    // matrix_init_le(matrix, 5, 5);
    matrix_init_chan(matrix, 5, 5);
    // matrix[0][0] = 1;
    xuat_matrix(matrix, 5, 5);
    int x = tim_so_chan_dau_tien(matrix,5,5);
    if( x != -1){
        printf("So chan dau tien trong ma tran la : %d\r\n", x);
    } 
    else
    {
        printf("Khong co so chan trong ma tran \r\n");
        printf("So le dau tien trong ma tran la: %d \r\n", tim_so_le_dau_tien(matrix,5,5));
    }

    return 0;
}

