#include <stdio.h>
#include <mm_malloc.h>

// #define WeightType int
// #define DataType char

// 数组最大值
#define MaxVertexNum 100

typedef int WeightType;

typedef char DataType;

// 图的类型定义
typedef struct GNode *PtrToGNode;

struct GNode
{
    // 顶点数
    int VertexNum;

    // 边数
    int EdgeNum;

    // 两个顶点之间的是否有边的二维数组
    WeightType G[MaxVertexNum][MaxVertexNum];

    // 顶点上的所对应存储的数据
    DataType data[MaxVertexNum];
};

// 图的结构指针
typedef PtrToGNode MGraph;

// 顶点类型
typedef int Vertex;

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

MGraph CreateGraph(int VertexNum);
Edge CreateEdge(Vertex V1, Vertex V2, WeightType Weight);
void InsertEdge(MGraph Graph, Edge E);
void PrintGraph(MGraph Graph);

int main()
{
    // 初始化图
    MGraph Graph = CreateGraph(10);

    PrintGraph(Graph);

    // 插入边
    Edge e1 = CreateEdge(0, 0, 2);
    Edge e2 = CreateEdge(9, 1, 3);
    InsertEdge(Graph, e1);
    InsertEdge(Graph, e2);

    PrintGraph(Graph);

    return 0;
}

/**
 * @brief Create a Graph object
 *
 * @param VertexNum
 * @return MGraph
 */
MGraph CreateGraph(int VertexNum)
{
    MGraph Graph;

    Vertex v, w;

    Graph = (MGraph)malloc(sizeof(struct GNode));

    Graph->VertexNum = VertexNum;

    Graph->EdgeNum = 0;

    for (v = 0; v < Graph->VertexNum; v++)
    {
        for (w = 0; w < Graph->VertexNum; w++)
        {
            Graph->G[v][w] = 0;
        }
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
    Edge E;

    E = (Edge)malloc(sizeof(struct ENode));

    E->V1 = V1;
    E->V2 = V2;
    E->Weight = Weight;

    return E;
}

/**
 * @brief 向图中插入有向边
 *
 * @param Graph
 * @param E
 */
void InsertEdge(MGraph Graph, Edge E)
{
    // 插入边
    Graph->G[E->V1][E->V2] = E->Weight;

    // 若是无向边, 还要插入边 <V2, V1>
    // Graph->G[E->V2][E->V1] = E->Weight;
}

/**
 * @brief 打印图
 *
 * @param Graph
 */
void PrintGraph(MGraph Graph)
{
    Vertex v, w;

    printf("-------- 开始打印图:\n");

    printf("  ");
    for (v = 0; v < Graph->VertexNum; v++)
    {
        printf("%d ", v);
    }
    printf("\n");

    for (v = 0; v < Graph->VertexNum; v++)
    {
        printf("%d ", v);
        for (w = 0; w < Graph->VertexNum; w++)
        {
            printf("%d ", Graph->G[v][w]);
        }
        printf("\n");
    }

    printf("-------- 结束打印图\n");
}