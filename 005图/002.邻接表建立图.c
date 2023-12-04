#include <stdio.h>
#include <mm_malloc.h>

// 最大顶点数
#define MaxVertexNum 100

// 权重
typedef int WeightType;

//
typedef char DataType;

// 顶点类型
typedef int Vertex;

// 链表邻接点的指针
typedef struct AdjVNode *PtrToAdjVNode;

// 链表邻接点
struct AdjVNode
{
    // 邻接点下标
    Vertex AdjV;

    // 边权重
    WeightType Weight;

    // 下个邻接点
    PtrToAdjVNode Next;
};

// 邻接表节点类型
struct VNode
{
    // 起始边的情况
    PtrToAdjVNode FirstEdge;

    // 顶点数据
    DataType Data;
};

// 邻接表类型
typedef struct VNode AdjList[MaxVertexNum];

// 定义图类型的指针类型
typedef struct GNode *PtrToGNode;

// 定义图类型
struct GNode
{
    // 顶点数
    int VertexNum;

    // 边数
    int EdgeNum;

    // 邻接表
    AdjList G;
};

// 简化图类型的指针类型
typedef PtrToGNode LGraph;

// 边的类型
typedef struct ENode *Edge;
struct ENode
{
    // 有向边 V1, V2
    Vertex V1;
    Vertex V2;

    // 权重
    WeightType Weight;
};

LGraph CreateGraph(int VertexNum);
Edge CreateEdge(Vertex V1, Vertex V2, WeightType Weight);
void InsertEdge(LGraph Graph, Edge E);
void InsertDirectEdge(LGraph Graph, Vertex V1, Vertex V2, WeightType Weight);
PtrToAdjVNode CreateAdjVNode(Vertex V, WeightType Weight);
void InsertEdgeByVertex(LGraph Graph, Vertex V, PtrToAdjVNode newVNode);
void PrintGraph(LGraph Graph);

int main()
{
    LGraph Graph = CreateGraph(10);

    InsertDirectEdge(Graph, 1, 2, 1);
    InsertDirectEdge(Graph, 1, 3, 2);
    InsertDirectEdge(Graph, 1, 4, 7);
    InsertDirectEdge(Graph, 1, 8, 9);
    InsertDirectEdge(Graph, 3, 1, 9);
    InsertDirectEdge(Graph, 4, 3, 9);
    InsertDirectEdge(Graph, 5, 7, 9);

    PrintGraph(Graph);

    return 0;
}

/**
 * @brief Create a Graph object
 *
 * @param VertexNum
 * @return LGraph
 */
LGraph CreateGraph(int VertexNum)
{
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));

    Graph->VertexNum = VertexNum;

    Graph->EdgeNum = 0;

    for (Vertex v = 0; v < Graph->VertexNum; v++)
    {
        Graph->G[v].FirstEdge = NULL;
    }

    return Graph;
}

/**
 * @brief Create a Edge object
 *
 * @param V1
 * @param V2
 * @param Weight
 * @return Edge
 */
Edge CreateEdge(Vertex V1, Vertex V2, WeightType Weight)
{
    Edge E = (Edge)malloc(sizeof(struct ENode));

    E->V1 = V1;

    E->V2 = V2;

    E->Weight = Weight;

    return E;
}

/**
 * @brief Create a Adj V Node object
 *
 * @param V
 * @param Weight
 * @return PtrToAdjVNode
 */
PtrToAdjVNode CreateAdjVNode(Vertex V, WeightType Weight)
{
    PtrToAdjVNode newVNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));

    newVNode->AdjV = V;

    newVNode->Weight = Weight;

    newVNode->Next = NULL;

    return newVNode;
}

/**
 * @brief
 *
 * @param Graph
 */
void InsertEdgeByVertex(LGraph Graph, Vertex V, PtrToAdjVNode newVNode)
{
    // 需要判断顶点最大值
    if (V > MaxVertexNum)
    {
        printf("超出最大顶点数");
        return;
    }

    PtrToAdjVNode LinkListEdge = Graph->G[V].FirstEdge;

    if (!LinkListEdge)
    {
        Graph->G[V].FirstEdge = newVNode;
    }
    else
    {
        while (LinkListEdge->Next)
        {
            LinkListEdge = LinkListEdge->Next;
        }
        LinkListEdge->Next = newVNode;
    }
}

/**
 * @brief 插入边<v1, v2>
 *
 * @param Graph
 * @param E
 */
void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode newVNode = CreateAdjVNode(E->V2, E->Weight);

    InsertEdgeByVertex(Graph, E->V1, newVNode);
}

/**
 * @brief 插入边 <v1, v2>
 *
 * @param Graph
 * @param V1
 * @param V2
 * @param Weight
 */
void InsertDirectEdge(LGraph Graph, Vertex V1, Vertex V2, WeightType Weight)
{
    PtrToAdjVNode newVNode = CreateAdjVNode(V2, Weight);

    InsertEdgeByVertex(Graph, V1, newVNode);

    // 若是无向边, 还需要插入 <V2, V1>
    PtrToAdjVNode newVNode1 = CreateAdjVNode(V1, Weight);
    InsertEdgeByVertex(Graph, V2, newVNode1);
}

void PrintGraph(LGraph Graph)
{
    printf("-----------开始打印:\n");

    for (int i = 0; i < Graph->VertexNum; i++)
    {
        printf("%d: ->", i);

        PtrToAdjVNode E = Graph->G[i].FirstEdge;

        while (E)
        {
            printf("%d(%d)", E->AdjV, E->Weight);

            E = E->Next;

            if (E)
            {
                printf("->");
            }
        }
        printf("\n");
    }

    printf("-----------打印结束:\n");
}