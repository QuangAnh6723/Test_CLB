#include<stdio.h>
#include<stdlib.h>

void matrix_init(int matrix[][5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand()%5;
        }  
    }
}

void xuat_matrix(int matrix[][5], int col, int row)
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


int main()
{
    int matrix[5][5] = {0}; 
    matrix_init(matrix, 5, 5);
    xuat_matrix(matrix, 5, 5);
    return 0;
}

