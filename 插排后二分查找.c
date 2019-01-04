#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *array, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        if (array[i] < array[i - 1])
        {
            tmp = array[i];
            for (j = i - 1; j >= 0 && tmp < array[j]; j--)
            {
                array[j + 1] = array[j];
            }
            array[j + 1] = tmp;
        }
    }
}

int BinarySearch(int *array, int key, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == key)
            return mid;
        else if (array[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int i, n, *array;
    printf("请输入数组的长度：");
    scanf("%d", &n);
    array = (int *) malloc(n * sizeof(int));
    printf("请依次输入数组的元素 [按空格分隔]：");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    InsertSort(array, n);
    printf("插入排序之后：");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n请输入要查找的元素: ");
    scanf("%d", &i);
    i = BinarySearch(array, i, 0, n - 1);
    if (i == -1)
        printf("要查找的元素不存在\n");
    else
        printf("查找到输入的元素\n");
}