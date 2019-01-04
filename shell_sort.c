#include <stdio.h>
#include <stdlib.h>

void ShellSort(int *array, int n)
{
    int k = n / 2;
    while (k > 0)
    {
        int i, j, tmp;
        for (i = k; i < n; i++)
        {
            if (array[i] < array[i - k])
            {
                tmp = array[i];
                for (j = i - k; j >= 0 && tmp < array[j]; j -= k)
                    array[j + k] = array[j];
                array[j + k] = tmp;
            }
        }
        k = k / 2;
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
    ShellSort(array, n);
    printf("排序后为：");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}