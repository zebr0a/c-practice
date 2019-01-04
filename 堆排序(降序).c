#include <stdio.h>
#include <stdlib.h>

void AdjustHeap(int *array, int low, int high)
{
    int i;
    array[0] = array[low];
    for (i = low * 2; i <= high; i *= 2)
    {
        if (i < high && array[i] > array[i + 1])
            i++;
        if (array[0] <= array[i])
            break;
        array[low] = array[i];
        low = i;
    }
    array[low] = array[0];
}

void HeapSort(int *array, int n)
{
    int i;
    for (i = n / 2; i > 0; i--)
    {
        AdjustHeap(array, i, n);
    }
    for (i = n; i > 1; i--)
    {
        array[0] = array[i];
        array[i] = array[1];
        array[1] = array[0];
        AdjustHeap(array, 1, i - 1);
    }
}

int main()
{
    int i, n;
    int *array;
    printf("请输入数组的大小：");
    scanf("%d", &n);
    array = (int*) malloc(sizeof(int) * (n + 1));
    printf("请输入数据（用空格分隔）：");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
    }
    HeapSort(array, n);
    printf("排序后为：");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}