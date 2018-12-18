#include <stdio.h>
#include <stdlib.h>

#define bool int
#define FALSE 0
#define TRUE 1

#define HASH_SIZE 11
#define NULLKEY -32767
#define OVERFLOW -2

typedef struct HashTable
{
    int *element;
}HashTable;

void Init(HashTable *p)
{
    int i;
    p->element = (int *)malloc(HASH_SIZE * sizeof(int));
    if (!p)
        exit(OVERFLOW);
    for (i = 0; i < HASH_SIZE; i++)
        p->element[i] = NULLKEY;
}

int Hash(int key)
{
    return key % HASH_SIZE;
}

bool InsertHash(HashTable *p, int elem)
{
    int key = Hash(elem), k = 1, i = 1, flag = -1, addr;
    addr = key;
    while (p->element[addr] != NULLKEY)
    {
        addr = (addr + k) % HASH_SIZE;
        if (key == addr)
        {
            printf("lack of memory\n");
            return FALSE;
        }
        if (k < 0)
            i++, flag *= -1;
        k = i * i * flag;
    }
    p->element[addr] = elem;
    return TRUE;
}

int Search(HashTable p, int elem)
{
    int key = Hash(elem), k = 1, i = 1, flag = -1, addr;
    addr = key;
    while (p.element[addr] != elem)
    {
        addr = (addr + k) % HASH_SIZE;
        if (key == addr)
            return -1;
        if (k < 0)
            i++, flag *= -1;
        k = i * i * flag;
    }
    return addr;
}

void Traverse(HashTable p)
{
    int i;
    for (i = 0; i < HASH_SIZE; i++)
        printf("%d ", p.element[i]);
}

int main()
{
    // 1 1 2 6 1 9 0 1 4
    int a[9] = {12, 45, 2, 6, 78, 9, 0, 1, 15}, i, res;
    HashTable H;
    Init(&H);
    for (i = 0; i < 9; i++)
    {
        InsertHash(&H, a[i]);
    }
    Traverse(H);
    res = Search(H, 15);
    if (res != -1)
        printf("查询成功，地址为: %d\n", res);
    else
        printf("查询失败\n");

    return 0;

}

