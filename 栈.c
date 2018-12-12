#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INIT_SIZE 20
#define INCREMENT_SIZE 5

typedef int SElemType;
typedef int Status;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int size;
}SqStack;

Status InitStack(SqStack *s)
{
    s->base = (SElemType *) malloc(INIT_SIZE * sizeof(SElemType));
    if (!s->base)
        exit(OVERFLOW);
    s->top = s->base;
    s->size = INIT_SIZE;

    return OK;
}

Status DestroyStack(SqStack *s)
{
    free(s->base);
    s->base = NULL;
    s->top = NULL;
    s->size = 0;

    return OK;
}

Status ClearStack(SqStack *s)
{
    s->top = s->base;
    return OK;
}

Status IsEmpty(SqStack s)
{
    if (s.base == s.top)
        return TRUE;
    return FALSE;
}

int GetLength(SqStack s)
{
    // int i = 0;
    // while(s->base + i < s->top)
    //     i++;
    // return i;
    // 循环注意事项：
    // 1. 循环是为了得到什么，哪一刻或者是哪个条件
    // 2. 循环的初始值是什么，它对应什么样的状态
    // 3. 不进入循环是什么情况
    // 4. 前后两个状态变化的量有哪些?

    return s.top - s.base;
}

int TGetLength(SqStack *s)
{
    return s->top - s->base;
}

int TTGetLength(SqStack *s)
{
    return (s->top - s->base)/sizeof(SElemType);
}

Status GetTop(SqStack s, SElemType *e)
{
    if (s.top == s.base)
        return ERROR;
    // 这儿采用值传递的参数，不修改真正top指针位置
    *e = *(--s.top);
    return OK;
}

Status Push(SqStack *s, SElemType e)
{
    // 没有除sizeof(SElemType)
    if (s->top - s->base >= s->size)
    {
        s->base = (SElemType *) realloc(s->base, (s->size + INCREMENT_SIZE) * sizeof(SElemType));
        if (!s->base)
            exit(OVERFLOW);
        s->top = s->base + s->size;
        s->size += INCREMENT_SIZE;
    }

    *s->top = e;
    s->top++;
    return OK;
}

Status Pop(SqStack *s, SElemType *e)
{
    if (s->top == s->base)
        return ERROR;
    s->top--;
    *e = *s->top;
    return OK;
}

void visit(SElemType e)
{
    printf("%d ", e);
}

Status TraverseStack(SqStack s, void(*visit)(SElemType))
{
    while (s.top > s.base)
    {
        visit(*s.base);
        s.base ++;
    }
    return OK;
}

int main()
{
    SqStack S;
    if (InitStack(&S))
    {
        SElemType e;
        int i;

        printf("init_success\n");

        if (IsEmpty(S))
            printf("Stack is empty\n");

        for (i = 0; i < 10; i++)
            Push(&S, i);

        GetTop(S, &e);
        printf("The top element is %d\n", e);

        printf("length is %d\n", GetLength(S));

        Pop(&S, &e);
        printf("Pop element is %d\n", e);

        printf("use *s length is %d\n", TGetLength(&S));
        printf("use *s and sizeof length is %d\n", TTGetLength(&S));

        // 无论使用visit, &visit, *visit, **visit都可以，因为visit可以视为一个指针常量，其存储的是它自身的地址
        TraverseStack(S, *visit);
        if (DestroyStack(&S))
            printf("\ndestroy_success\n");
    }
}
