#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int low, high;
    struct LNode *next;
}LNode, *NodePtr;

typedef struct Stack
{
    NodePtr base, rear;
}Stack;

void QuickSort(int *array, int low, int high)
{
    int pivotlock, tmp;

    Stack S;
    S.base = S.rear = (NodePtr) malloc(sizeof(LNode));
    S.base->next = NULL;

    NodePtr p = (NodePtr) malloc(sizeof(LNode));
    p->low = low;
    p->high = high;
    p->next = S.rear->next;
    S.rear->next = p;
    S.rear = p;

    while (S.base != S.rear)
    {
        int start, end;
        start = low = S.rear->low;
        end = high = S.rear->high;
        pivotlock = array[low];

        p = S.base;
        while(p->next != S.rear)
            p = p->next;
        S.rear = p;
        p = p->next;
        S.rear->next = NULL;
        free(p);

        if (low >= high)
            continue;

        while (low < high)
        {
            while (low < high && array[high] > pivotlock)
                high--;
            array[low] = array[high];
            while (low < high && array[low] < pivotlock)
                low++;
            array[high] = array[low];
        }
        array[low] = pivotlock;

        p = (NodePtr) malloc(sizeof(LNode));
        p->low = start;
        p->high = low - 1;
        p->next = S.rear->next;
        S.rear->next = p;
        S.rear = p;

        p = (NodePtr) malloc(sizeof(LNode));
        p->low = low + 1;
        p->high = end;
        p->next = S.rear->next;
        S.rear->next = p;
        S.rear = p;
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