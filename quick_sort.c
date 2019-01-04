#include <stdio.h>
#include <stdlib.h>

// pivotekey可以是只采用第一个值，也可以采用拉链法动态变化
int Partition(int *array, int low, int high)
{
    int tmp = array[low], pivotekey = array[low];
    while (low < high)
    {
        while (low < high && array[high] >= pivotekey)
            high--;
        array[low] = array[high];
        while (low < high && array[low] <= pivotekey)
            low++;
        array[high] = array[low];
    }
    array[low] = tmp;
    return low;
}

void QuickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivotloc = Partition(array, low, high);
        QuickSort(array, low, pivotloc - 1);
        QuickSort(array, pivotloc + 1, high);
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
    QuickSort(array, 0, n - 1);
    printf("排序后为：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}