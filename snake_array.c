#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define TRUE 1
#define TALSE 0

void FillMatrix(int *a, int n)
{
    int i = 0, j = 0, round, sum;
    sum = 0;
    for (round = 0; round < (n + 1) / 2; round++)
    {
        for (; j < n - round - 1; j++)
            a[i * n + j] =  sum++;
        for (; i < n - round - 1; i++)
            a[i * n + j] = sum++;
        for (; j > round; j--)
            a[i * n + j] = sum++;
        for (; i > round + 1; i--)
            a[i * n + j] = sum++;
    }
    a[i * n + j] = sum;
}

void Traverse(int *a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%-4d", a[i * n + j]);
        printf("\n");
    }
}

int main()
{
    int matrix[5][5];
    memset((int*)matrix, 0, sizeof(matrix));
    FillMatrix((int*)matrix, 5);
    Traverse((int*)matrix, 5);

    return 0;
}