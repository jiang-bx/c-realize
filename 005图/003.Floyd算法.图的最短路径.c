#include <stdio.h>
#include <mm_malloc.h>

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
void test();
void FindAnimal(MGraph Graph);
void Floyd(MGraph Graph, WeightType D[][MaxVertexNum]);

int main()
{
    test();
    return 0;
}

void test()
{
    // 初始化图
    MGraph Graph = CreateGraph(6);

    // 顶点从 1 开始计算, 但是用 0 表示 1

    // 插入边
    InsertEdge(Graph, CreateEdge(3, 4, 70));
    InsertEdge(Graph, CreateEdge(1, 2, 1));
    InsertEdge(Graph, CreateEdge(5, 4, 50));
    InsertEdge(Graph, CreateEdge(2, 6, 50));
    InsertEdge(Graph, CreateEdge(5, 6, 60));
    InsertEdge(Graph, CreateEdge(1, 3, 70));
    InsertEdge(Graph, CreateEdge(4, 6, 60));
    InsertEdge(Graph, CreateEdge(3, 6, 80));
    InsertEdge(Graph, CreateEdge(5, 1, 100));
    InsertEdge(Graph, CreateEdge(2, 4, 60));
    InsertEdge(Graph, CreateEdge(5, 2, 80));

    PrintGraph(Graph);

    FindAnimal(Graph);
}

void FindAnimal(MGraph Graph)
{
    WeightType D[MaxVertexNum][MaxVertexNum];
    WeightType MaxDist;
    WeightType MinDist;

    Vertex Animal, i;

    Floyd(Graph, D);
}

/**
 * @brief Floyd 算法
 *
 * @param Graph
 * @param D
 */
void Floyd(MGraph Graph, WeightType D[][MaxVertexNum])
{
    Vertex i, j, k;

    // 初始化
    for (i = 0; i < Graph->VertexNum; i++)
    {
        for (j = 0; j < Graph->VertexNum; j++)
        {
            D[i][j] = Graph->G[i][j];
        }
    }

    // printf("  ");
    // for (i = 0; i < Graph->VertexNum; i++)
    // {
    //     printf("%d ", i);
    // }
    // printf("\n");

    // for (i = 0; i < Graph->VertexNum; i++)
    // {
    //     printf("%d ", i);
    //     for (j = 0; j < Graph->VertexNum; j++)
    //     {

    //         printf("%d ", D[i][j]);
    //     }
    //     printf("\n");
    // }

    for (k = 0; k < Graph->VertexNum; k++) // 中转站
    {
        for (i = 0; i < Graph->VertexNum; i++) // i 为起点
        {
            for (j = 0; j < Graph->VertexNum; j++) // j 为终点
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];

                    // printf("%d\n", D[i][k] + D[k][j]);

                    if (i == j && D[i][j] < 0)
                    {
                        return;
                    }
                }
            }
        }
    }

    printf("  ");
    for (i = 0; i < Graph->VertexNum; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < Graph->VertexNum; i++)
    {
        printf("%d ", i);
        for (j = 0; j < Graph->VertexNum; j++)
        {

            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
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

    E->V1 = V1 - 1;
    E->V2 = V2 - 1;
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
    Graph->G[E->V2][E->V1] = E->Weight;
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
        printf("%d   ", v);
    }
    printf("\n");

    for (v = 0; v < Graph->VertexNum; v++)
    {
        printf("%d ", v);
        for (w = 0; w < Graph->VertexNum; w++)
        {
            if (Graph->G[v][w] < 10)
            {
                printf("%d   ", Graph->G[v][w]);
            }
            else if (Graph->G[v][w] < 100)
            {
                printf("%d  ", Graph->G[v][w]);
            }
            else
            {
                printf("%d ", Graph->G[v][w]);
            }
        }
        printf("\n");
    }

    printf("-------- 结束打印图\n");
}