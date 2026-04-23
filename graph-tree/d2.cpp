/*
  this is accepted code
*/
#include<stdio.h>
#include<stdlib.h>

#define MAXN 200
#define INFINITY 100000

typedef int WeightType;
typedef int Vertex;

typedef struct GNode *PtrToGNode;
typedef PtrToGNode MGraph;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MAXN][MAXN];
};

typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;
struct ENode {
    Vertex V1, V2;
    WeightType W;
};

MGraph CreateGraph(int VertexNum) {
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    Vertex i,j;
    for(i=0; i<Graph->Nv; i++)
        for(j=0; j<Graph->Nv; j++)
            Graph->G[i][j] = INFINITY;

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E) {
    Graph->G[E->V1][E->V2] = E->W;
    Graph->G[E->V2][E->V1] = E->W;
}

MGraph BuildGraph(int VertexNum, int EdgeNum) {
    MGraph Graph = CreateGraph(VertexNum);
    Graph->Ne = EdgeNum;

    Edge E = (Edge)malloc(sizeof(struct ENode));
    int i;
    for(i=0; i<Graph->Ne; i++) {
        scanf("%d %d", &E->V1, &E->V2);
        E->V1--;
        E->V2--;
        E->W = 1;
        InsertEdge(Graph, E);
    }

    return Graph;
}

int IsEdge(MGraph Graph, Vertex V1, Vertex V2) {
    if(Graph->G[V1][V2] == INFINITY)
        return 0;
    else
        return 1;
}

int main() {

    int N, M, K, TN, i, j, tmp;
    Vertex InputArr[MAXN+1] = {0};
    int Visited[MAXN] = {0};

    scanf("%d %d", &N, &M);
    MGraph Graph = BuildGraph(N, M);

    scanf("%d", &K);
    for(i=0; i<K; i++) {
        scanf("%d", &TN);
        if(TN != Graph->Nv+1) {
            printf("NO\n");
            while(TN != 0) {
                scanf("%d", &tmp);
                TN--;
            }
        } else {
            
            for(j=0; j<Graph->Nv; j++) {
                Visited[j] = 0;
            }

            

            for(j=0; j<Graph->Nv+1; j++) {
                scanf("%d", &InputArr[j]);
                InputArr[j]--;
            }
            for(j=0; j<Graph->Nv; j++) {
                if(IsEdge(Graph, InputArr[j], InputArr[j+1]))
                    Visited[InputArr[j+1]] = 1;
                else {
                    printf("NO\n");
                    break;
                }
            }
            if(j == Graph->Nv) {
                for(j=0; j<Graph->Nv; j++) {
                    if(Visited[j] == 0) {
                        printf("NO\n");
                        break;
                    }
                }
                if(j == Graph->Nv)
                    printf("YES\n");
            }
        }
    }
    return 0;
}