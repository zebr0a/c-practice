#include <stdio.h>
#include <stdlib.h>

void HeapAdjust(int *array, int s, int m)
{
    int i, tmp;
    tmp = array[s];
    for (i = s * 2 + 1; i <= m; i = i * 2 + 1)
    {
        if (i < m && array[i] < array[i + 1])
            i++;
        if (tmp >= array[i])
            break;
        array[s] = array[i];
        s = i;
    }
    array[s] = tmp;
}

void HeapSort(int *array, int n)
{
    int i, tmp;
    for (i = (n - 1) / 2; i >= 0; i--)
        HeapAdjust(array, i, n - 1);
    for (i = n - 1; i > 0; i--)
    {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        HeapAdjust(array, 0, i - 1);
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
    HeapSort(array, n);
    printf("排序后为：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}