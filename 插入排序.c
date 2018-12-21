#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *array, int n)
{
    int i, j ,k, tmp;
    for (i = 1; i < n; i++)
    {
        if (*(array + i) < *(array + i - 1))
        {
            tmp = *(array + i);
            *(array + i) = *(array + i - 1);
            for (j = i - 1; j > 0 && tmp < *(array + j - 1); j--)
            {
                *(array + j) = *(array + j - 1);
            }
            *(array + j) = tmp;
        }
        for (k = 0; k < n; k++)
            printf("%d ", *(array + k));
        printf("\n");
    }
}

int main()
{
    int i, n;
    int *array;
    printf("please input the size: ");
    scanf("%d", &n);
    array = (int*) malloc(sizeof(int) * n);
    printf("please input the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", array + i);
    InsertSort(array, n);
    printf("after sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(array + i));
    printf("\n");
}