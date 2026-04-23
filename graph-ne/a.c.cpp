#include <iostream>
#include <vector>
using namespace std;
const int max_vertex_number=100;
class Map{
    int matrix[max_vertex_number][max_vertex_number];
    int distance[max_vertex_number]={0};
    int vertex_number;
    string vertex[max_vertex_number];
    vector<int> path[max_vertex_number];
    string start;
    bool done[max_vertex_number]={false};
public:
    Map(){
        cin>>vertex_number;
        for(int i=0;i<vertex_number;i++)
            cin>>vertex[i];
        for(int i=0;i<vertex_number;i++)
            for(int j=0;j<vertex_number;j++)
                cin>>matrix[i][j];
        cin>>start;
    }
    void Dijkstra(){
        int startIndex= getIndex(start);
        for(int i=0;i<vertex_number;i++){
            if(matrix[startIndex][i]){
                distance[i]=matrix[startIndex][i];
                path[i].push_back(startIndex);
                path[i].push_back(i);
            }
        }
        done[startIndex]=true;
        for(int i=0;i<vertex_number-1;i++){
            int minDistance=0x3f3f3f3f;
            int minIndex;
            for(int j=0;j<vertex_number;j++)
                if(done[j]== false&&distance[j]&&distance[j]<minDistance){
                    minIndex=j;
                    minDistance=distance[j];
                }
            done[minIndex]=true;
            for(int j=0;j<vertex_number;j++)
                if(matrix[minIndex][j]&&done[j]== false&&(minDistance+matrix[minIndex][j]<distance[j]||distance[j]==0)){
                    distance[j]=minDistance+matrix[minIndex][j];
                    path[j]=path[minIndex];
                    path[j].push_back(j);
                }
        }
    }
    int getIndex(string&data){
        for(int i=0;i<vertex_number;i++)
            if(data==vertex[i])
                return i;
    }
    void Show(){
        Dijkstra();
        for(int i=0;i<vertex_number;i++){
            if(i== getIndex(start))
                continue;
            if(distance[i]){
                cout<<start<<'-'<<vertex[i]<<'-'<<distance[i]<<"----[";
                for(auto&it:path[i])
                    cout<<vertex[it]<<' ';
                cout<<"]\n";
            }else cout<<start<<'-'<<vertex[i]<<"--1"<<endl;
        }
    }
};
int main() {
    int t;
    cin>>t;
    while(t--){
        Map test;
        test.Show();
    }
}
