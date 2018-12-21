#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

bool FindArray(int *a, int key, int row, int col)
{
    int i = 0,j = col - 1;
    while (i < row && j >= 0)
    {
        if (key == a[i*col + j])
            return TRUE;
        else if (key < a[i*col + j])
            j--;
        else
            i++;
    }
    return FALSE;
}

int main()
{
    bool result;
    int input, array[4][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}, {4, 5, 6, 7, 8}};
    printf("please input number: \n");
    scanf("%d", &input);
    result = FindArray((int*)array, input, 4, 5);
    printf("the result is %d", result);

    return 0;
}