/*
1) write a program for multiply two 2d matrox considering all the options (size 50 50)
2) create a linked list and add a node
2) wap to delete a node from a linked list
*/

#include <stdio.h>

int main(){
    int a[50][50];

    int b[50][50];

    int c[50][50] = {0};

    int row1, col1, row2, col2;



    printf("Enter Matrix 1:\n");
    printf("Enter no of rows: ");
    scanf("%d", &row1);
    printf("Enter no of cols: ");
    scanf("%d", &col1);

    for(int i = 0; i< row1; i++)
    {
        for(int j = 0; j < col1; j++)
        {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i< row1; i++)
        {
            for(int j = 0; j < col1; j++)
            {
                printf("%d ", a[i][j]);

            }
            printf("\n");
        }

    printf("Enter Matrix 2:\n");
    printf("Enter no of rows: ");
    scanf("%d", &row2);
    printf("Enter no of cols: ");
    scanf("%d", &col2);

    for(int i = 0; i< row2; i++){
        for(int j = 0; j < col2; j++){
            printf("Enter b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for(int i = 0; i< row2; i++)
        {
            for(int j = 0; j < col2; j++)
            {
                printf("%d ", b[i][j]);

            }
            printf("\n");
        }

    if (col1 == row2)
    {
        for(int i = 0; i< row1; i++)
        {
            for(int j = 0; j < col2; j++)
            {
                for(int k = 0; k < col1; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("Product of matrix is:\n");

        for(int i = 0; i< row1; i++)
        {
            for(int j = 0; j < col2; j++)
            {
                printf("%d ", c[i][j]);

            }
            printf("\n");
        }

    } else {
        printf("Matrix multiplication is not possible");
    }



    return 0;

}
