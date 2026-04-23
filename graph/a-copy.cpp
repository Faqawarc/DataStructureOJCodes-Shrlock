#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define MAX_VERTEX_NUM 100   
typedef int OtherInfo;       
typedef char VertexType;    
typedef char GraphKind;    

typedef struct ArcNode {
    int  adjvex;         
    struct ArcNode* nextarc; 
    OtherInfo info; 
}ArcNode;

typedef struct VNode {
    VertexType  vexdata;
    ArcNode* firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList  vertices;
    int  vexnum;
    int arcnum;
    GraphKind kind;
} ALGraph;

int LocateVex(ALGraph& G, char v) {
    for (int i = 0; i < G.vexnum; i++) {
        if (v == G.vertices[i].vexdata) {
            return i;
            break;
        }
    }
    return -1;
}

void CreateGraph(ALGraph& G) {
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i) {
        cin >> G.vertices[i].vexdata;
        G.vertices[i].firstarc = NULL;
    }
    for (int j = 0; j < G.arcnum; j++) {
        char v0, v1;
        cin >> v0 >> v1;
        char x = LocateVex(G, v0);
        char y = LocateVex(G, v1);
        ArcNode* pi = new ArcNode;
        pi->adjvex = y;
        pi->nextarc = G.vertices[x].firstarc;
        G.vertices[x].firstarc = pi;
    }
}

void PrintfGraphAdjList(ALGraph& G) {
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode* p = G.vertices[i].firstarc;
        cout << i << " " << G.vertices[i].vexdata << "-";
 
        vector<int> adjvexList;
 
        while (p) {
            adjvexList.push_back(p->adjvex);
            p = p->nextarc;
        }
 
        sort(adjvexList.begin(), adjvexList.end());
 
        for (int j = 0; j < adjvexList.size(); j++) {
            cout << adjvexList[j] << "-";
        }
 
        cout << "^" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ALGraph G;
        CreateGraph(G);
        PrintfGraphAdjList(G);
        return 0;
    }
 
}