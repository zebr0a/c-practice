#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 20
#define N 999
#define TRUE 1;

typedef int bool;
typedef char VexType;

typedef struct EdgeNode
{
    int adjvex, weight;
    struct EdgeNode *next;
}EdgeNode, *EdgeLink;

typedef struct VexNode
{
    VexType data;
    EdgeLink firstEdge;
}VexNode, AdjList[MAX_NUM];

typedef struct ALGraph
{
    AdjList adjList;
    int vexNum, edgeNum;
}ALGraph;

bool CreateGraph(ALGraph *G)
{
    int i, j, k, w;
    EdgeLink e;
    printf("请输入定点数目和边数:\n");
    scanf("%d", &G->vexNum);
    scanf("%d", &G->edgeNum);
    getchar();
    printf("请输入个各顶点的数据:\n");
    for (i = 0; i < G->vexNum; i++)
    {
        scanf("%c", &G->adjList[i].data);
        if (G->adjList[i].data == '\n')
        {
            i--;
            continue;
        }
        G->adjList[i].firstEdge = NULL;
    }

    printf("请输入边(Vi, Vj)的顶点序号和权重:\n");
    for (k = 0; k < G->edgeNum; k++)
    {
        scanf("%d", &i);
        scanf("%d", &j);
        scanf("%d", &w);
        e = (EdgeLink) malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->weight = w;
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;
        e = (EdgeLink) malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->weight = w;
        e->next = G->adjList[j].firstEdge;
        G->adjList[j].firstEdge = e;
        printf("\n");
    }

    return TRUE;
}

void Dij(ALGraph G, int i)
{
    int vis[G.vexNum], d[G.vexNum], tmp, k, v;
    EdgeLink p;
    // memset是按照字节设置值，所以常用于清零
    // sizeof()返回所占字节长度
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));

    for (k = 0; k < G.vexNum; k++)
        d[k] = N;

    p = G.adjList[i].firstEdge;
    while (p)
    {
        d[p->adjvex] = p->weight;
        p = p->next;
    }
    d[i] = 0;
    vis[i] = 1;

    for (i = 0; i < G.vexNum; i++)
    {
        tmp = N;
        for (k = 0; k < G.vexNum; k++)
        {
            if (tmp > d[k] && !vis[k])
            {
                tmp = d[k];
                v = k;
            }
        }
        vis[v] = 1;
        p = G.adjList[v].firstEdge;
        while (p)
        {
            if (!vis[p->adjvex])
            {
                d[p->adjvex] = (d[p->adjvex] > tmp + p->weight) ? tmp + p->weight : d[p->adjvex];
            }
            p = p->next;
        }
    }

    for (i = 0; i < G.vexNum; i++)
        printf("%d ", d[i]);

}

int main()
{
    int i;
    ALGraph G;
    CreateGraph(&G);
    printf("请输入从哪个节点开始:");
    scanf("%d", &i);
    printf("从%d到各顶点的距离为:\n", i);
    Dij(G, i);
    printf("\n");
}