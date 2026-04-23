#include<iostream>
using namespace std;
#define N 100

class ArcNode {
public:
    int adjvex;
    ArcNode *nextarc;
    int weight;
    ArcNode(int adj,ArcNode *next) {
        adjvex=adj;
        nextarc=next;
    }
};
 
class VNode {
public:
    string data;
    ArcNode *firstarc;
    VNode() {
        data="";
    }
};
 
class ALGraph {
public:
    VNode vertices[N];
    ArcNode *pRow[N];
    int vexnum,arcnum;
    ALGraph() {
        for(int i=0;i<N;i++) {
            vertices[i].firstarc=NULL;
            pRow[i]=NULL;
        }
    }
    int getindex(string v) {
        for(int i=0;i<vexnum;i++) {
            if(vertices[i].data==v)
                return i;
        }
        return -1;
    }
    void CreateALGraph() {
        string d;
        cin>>vexnum>>arcnum;
        for(int i=0;i<vexnum;i++) {
            cin>>d;
            vertices[i].data=d;
        }
        string v1,v2;
        for(int i=0;i<arcnum;i++) {
            cin>>v1>>v2;
            int index1=getindex(v1);
            int index2=getindex(v2);
            ArcNode *edge=new ArcNode(index2,NULL);
            if(vertices[index1].firstarc==NULL) {
                vertices[index1].firstarc=edge;
            }
            else {
                pRow[index1]->nextarc=edge;
            }
            pRow[index1]=edge;
        }
    }
    void display() {
        for(int i=0;i<vexnum;i++) {
            cout<<i<<" ";
            ArcNode *p=vertices[i].firstarc;
            cout<<vertices[i].data<<"-";
            while(p!=NULL) {
                cout<<p->adjvex<<"-";
                p=p->nextarc;
            }
            cout<<"^"<<endl;
        }
    }
};
 
int main() {
    int T;
    cin>>T;
    while(T--) {
        ALGraph g;
        g.CreateALGraph();
        g.display();
    }
    return 0;
}