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

typedef struct LNode{
    SElemType elem;
    struct LNode *next;
}LNode;

typedef struct Stack{
    LNode *base;
    LNode *top;
}Stack, *LinkStack;

Status InitStack(LinkStack *S)
{
    *S = (LinkStack)malloc(sizeof(Stack));
    if (!*S)
        exit(OVERFLOW);
    *S->base = NULL;
    *S->top = NULL;

    return OK;
}

Status ClearStack(LinkStack *S)
{
    LNode *p;
    while (p = *S->base) {
        S->base = S->base->next;
        free(p);
    }

    S->top = S->base;
    return OK;
}

Status DestroyStack(LinkStack *S)
{
    ClearStack(S);
    
    free(S->base);
    S->base = S->top = NULL;

    return OK;
}

Status IsEmpty(LinkStack S)
{
    if (S.base == S.top)
        return TRUE;
    return FALSE;
}

int GetLength(LinkStack S)
{
    return S.top - S.base;
}

Status GetTop(LinkStack S, SElemType *e)
{
    if (S.top == S.base)
        return ERROR;
    *e = S.top->elem;
}

Status Push(LinkStack *S, SElemType *e)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));

}
