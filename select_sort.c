#include <stdio.h>
#include <stdlib.h>

void SelectSort(int *array, int n)
{
    int i, j, k, tmp;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[k])
                k = j;
        if (k != i)
        {
            tmp = array[i];
            array[i] = array[k];
            array[k] = tmp;
        }
    }
}

int main()
{
    int i, n;
    int *array;
    printf("请输入数组的大小：");
    scanf("%d", &n);
    array = (int*) malloc(sizeof(int) * n);
    printf("请输入数据（用空格分隔）：");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    SelectSort(array, n);
    printf("排序后为：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}