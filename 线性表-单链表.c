#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        exit(OVERFLOW);
    (*L)->next = NULL;
}
// 为什么不直接修改L存储的地址，而是让*L去存储链表的地址
// 这涉及到采用指针参数的原因
/**
  * 1.函数参数与实际传入参数同类型的话，实际传入参数不会被修改，相当于函数体操作的是形参
    e.g 如果函数声明为void InitList(LinkList L) 直接传入LinkList类型参数, 结果初始化失败
        如果传入LNode 则可以初始化，当然逻辑需要修改 像(*L)->next 得改为 L->next

    2.采用指针参数，传入的参数为地址时，实际参数就会被修改。但是被传入的内容需要被分配空间。
    e.g void InitList(LinkList *L) 需要传入LinkList L,即已被申明的LinkList类型数据(实际上是指针类型数据)
        void InitList(LNode *L) 需要传入LNode L,由于LNode是结构体，LNode还需要先分配空间

    总结一下，有两个目的。第一是为了直接给声明的链表类型修改指向头结点LinkList L = &HeadNode, 这在函数中需要传LinkList
    的地址作为参数，使用指向指针的指针。第二点是假如不这么做，也可以通过直接传HeadNode地址给LNode*(LinkList)，在函数中
    修改HeadNode达到初始化的目的，这样的话，HeadNode的初始化需要在调用函数前手动提前完成。

    再提炼一下就是，传指针的指针既可以修改指针指向哪里(即指针本身的内容)，也可以修改指针被指向的内容；传指针本身，只能修改
    被指针指向的内容。
    e.g 指针的指针: L指不指向HeadNode, 修改HeadNode
        指针本身: 修改HeadNode
  */

void DestroyList(LinkList *L)
{
    LinkList temp;
    while(*L)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

void ClearList(LinkList L)
{
    LinkList p = L->next;
    L->next = NULL;
    DestroyList(&p);
}

Status isEmpty(LinkList L)
{
    if (L->next)
        return FALSE;
    return TRUE;
}

int GetLength(LinkList L)
{
    int i = 0;
    LinkList p = L;
    while(p = p->next)
        i++;
    return i;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
    int j = 1;
    LinkList p = L;
    while((p = p->next) && j < i)   // 赋值运算优先级小于逻辑运算
        j++;
    if (!p || i < 1)
        return ERROR;
    *e = p->data;
    return OK;
}

Status compare(ElemType e1, ElemType e2)
{
    if (e1 == e2)
        return 0;
    else if (e1 > e2)
        return 1;
    else
        return -1;
}

int FindElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 1;
    LinkList p = L->next;
    while(p)
    {
        if (!compare(p->data, e))
            return i;
        p = p->next;
        i++;
    }
    return 0;
}

Status PreElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    LinkList p = L->next;
    while(p->next)
    {
        if (p->next->data == cur_e)
        {
            *pre_e = p->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    LinkList p = L->next;
    while(p->next)
    {
        if (p->data == cur_e)
        {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}


Status InsertElem(LinkList L, int i, ElemType e)
{
    int j = 0;
    LinkList s, p = L;
    while(p && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if (!p || i < 1)
        return ERROR;

    s = (LinkList) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status DeleteElem(LinkList L, int i, ElemType *e)
{
    int j = 0;
    LinkList temp, p = L;
    while(p->next && j < i - 1)
    {
        j++;
        p = p->next;
    }

    if (!p->next || i < 1)
        return ERROR;

    temp = p->next;
    p->next = temp->next;
    *e = temp->data;
    free(temp);

    return OK;
}

void visit(ElemType e)
{
    printf("%d ", e);
}


void TraverseList(LinkList L, void (*visit)(ElemType))
{
    LinkList p = L;
    while(p = p->next)
        visit(p->data);
}

int main()
{
    LinkList L;
    InitList(&L);
    ElemType e;
    int i;
    if (L)
        printf("init success\n");

    if (isEmpty(L))
        printf("list is empty\n");

    for (i = 0; i < 10; i++)
        InsertElem(L, i + 1, i);

    if (GetElem(L, 1, &e))
        printf("The first element is %d\n", e);

    printf("length is %d\n", GetLength(L));

    printf("The 5 at %d\n", FindElem(L, 5, compare));

    PreElem(L, 6 , &e);
    printf("The 6's previous element is %d\n", e);

    NextElem(L, 6, &e);
    printf("The 6's next element is %d\n", e);

    DeleteElem(L, 1, &e);
    printf("delete first element is %d\n", e);

    printf("list:");
    TraverseList(L, visit);

    DestroyList(&L);
    if (!L)
        printf("\ndestroy success\n");
}