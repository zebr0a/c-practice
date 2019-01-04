#include <stdio.h>
#include <stdlib.h>

void BinarySort(int *array, int n)
{
    int i, j, tmp, mid, high, low;
    for (i = 1; i < n; i++)
    {
        if (array[i] < array[i - 1])
        {
            tmp = array[i];
            high = i - 1;
            low = 0;
            while (low <= high)
            {
                mid = (high + low) / 2;
                if (array[mid] <= tmp)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            for (j = i - 1; j > high; j--)
                array[j + 1] = array[j];
            array[j + 1] = tmp;
        }
    }
}

int main()
{
    int i, n;
    int *array;
    printf("请输入数组的大小：");
    scanf("%d", &n);
    array = (int *) malloc(n * sizeof(int));
    printf("请输入数据（用空格分隔)：");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    BinarySort(array, n);
    printf("排序后为：");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}