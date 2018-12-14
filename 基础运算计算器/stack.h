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

typedef struct SNode{
    SElemType elem;
    struct SNode *next;
}SNode, *SNodePtr;

typedef struct Stack{
    SNodePtr base;
    SNodePtr top;
}Stack;

Status InitStack(Stack *S)
{
    S->base = S->top = (SNodePtr)malloc(sizeof(SNode));
    if (!S->base)
        exit(OVERFLOW);
    S->base->next = NULL;

    return OK;
}

Status ClearStack(Stack *S)
{
    SNodePtr p = S->base->next;
    while (p) {
        S->top = p->next;
        free(p);
        p = S->top;
    }

    S->top = S->base;
    return OK;
}

Status DestroyStack(Stack *S)
{
    while (S->base) {
        S->top = S->base;
        S->base = S->base->next;
        free(S->top);
    }

    S->top = S->base;
    return OK;
}

Status IsEmpty(Stack S)
{
    if (S.base == S.top)
        return TRUE;
    return FALSE;
}

int GetLength(Stack S)
{
    int i = 0;
    while (S.base->next)
    {
        S.base = S.base->next;
        i++;
    }
    return i;
}

SElemType GetTop(Stack S)
{
    if (S.top == S.base)
        return ERROR;
    return S.top->elem;
}

Status Push(Stack *S, SElemType e)
{
    SNodePtr p = (SNodePtr) malloc(sizeof(SNode));
    if (!p)
        exit(OVERFLOW);
    p->elem = e;
    p->next = NULL;
    S->top->next = p;
    S->top = p;

    return OK;
}

SElemType Pop(Stack *S)
{
     SElemType e;

    if (S->base == S->top)
        return ERROR;

    SNodePtr p = S->base;
    while (p->next != S->top)
        p = p->next;
    p->next = NULL;
    e = S->top->elem;
    free(S->top);
    S->top = p;

    return e;
}

void visit(SElemType e)
{
    printf("%d ", e);
}

Status Traverse(Stack S, void(*visit)(SElemType))
{
    while (S.base != S.top)
    {
        visit(S.base->elem);
        S.base = S.base->next;
    }
    return OK;
}
