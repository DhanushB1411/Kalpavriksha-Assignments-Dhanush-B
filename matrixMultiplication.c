#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    int m, n;
    printf("Enter dim of matrix 1:\n");
    scanf("%d", &m);
    scanf("%d", &n);
    int matrix1[m][n];
    printf("Enter the matrix1 content :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (*(matrix1 + i) + j));
        }
    }

    int p, q;
    printf("Enter dim of matrix 2:\n");
    scanf("%d", &p);
    scanf("%d", &q);

    int matrix2[p][q];
    printf("Enter the matrix2 content :\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", (*(matrix2 + i) + j));
        }
    }

    if (n == p)
    {
        int ansMatrix[m][q];

        for (int firstMatrixRow = 0; firstMatrixRow < m; firstMatrixRow++)
        {

            for (int secondMatrixCol = 0; secondMatrixCol < q; secondMatrixCol++)
            {

                int sum = 0;
                for (int k = 0; k < n; k++)
                {
                    sum = sum + matrix1[firstMatrixRow][k] * matrix2[k][secondMatrixCol];
                }
                ansMatrix[firstMatrixRow][secondMatrixCol] = sum;
            }
        }

        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < q; j++)
            {

                printf("%d ", *(*(ansMatrix + i) + j));
            }

            printf("\n");
        }
    }
    else
    {
        printf("Not Possible");
    }

    return 0;
}