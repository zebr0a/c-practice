#include <stdio.h>
#include <stdlib.h>

void BinaryShell(int *array, int n)
{
    int i, j, m, k, tmp, mid, high, low;
    k = n / 2;
    while (k > 0)
    {
        for (i = 0; i < k; i++)
        {
            for (j = k + i; j < n; j += k)
            {
                if (array[j] <= array[j - k])
                {
                    tmp = array[j];
                    high = j - k;
                    low = i;
                    while (low <= high)
                    {
                        mid = (high + low) / (2 * k) * k + i;
                        if (array[low] <= tmp)
                            low = mid + k;
                        else
                            high = mid - k;
                    }
                    for (m = j; m > high + k; m -= k)
                        array[m] = array[m - k];
                    array[m] = tmp;
                }
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
    BinaryShell(array, n);
    printf("排序后为：");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}