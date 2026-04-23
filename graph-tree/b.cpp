#include <iostream>
#define MAX 500
#define MMM 10000
using namespace std;

struct Graph {
	
	string data[MAX];
	int Edge[MAX][MAX];
	int vexnum;
	int arcnum;
	Graph() {
		
		cin >> vexnum;
		for (int i = 0; i < vexnum; i++) {
			cin >> data[i];
		}
		
		cin >> arcnum;
		
		for (int i = 0; i < vexnum; i++) {
			for (int j = 0; j < vexnum; j++) {
				Edge[i][j] = MMM;
			}
		}
		string s1, s2;
		int weight;
		int index1, index2;
		for (int i = 0; i < arcnum; i++) {
			cin >> s1 >> s2 >> weight;
			index1 = get_index(s1);
			index2 = get_index(s2);
			Edge[index1][index2] = weight;
			Edge[index2][index1] = weight;
		}
	}
	int get_index(string s) {
		for (int i = 0; i < vexnum; i++) {
			if (s == data[i]) return i;
		}
		return -1;
	}
};
struct closeEdge {
	
	int lowcost_parent[2][MAX];
	
	closeEdge(Graph& g, string start) {
		int start_index = g.get_index(start);
		for (int j = 0; j < g.vexnum; j++) {
			lowcost_parent[0][j] = g.Edge[start_index][j];
			lowcost_parent[1][j] = start_index;
		}
	}
};
int flag[MAX];
int cont=0;
void Prim(Graph& g, closeEdge& c, string start) {
	int sum = 0;
	int start_index = g.get_index(start);
	int last_index;
	
	flag[cont] = start_index;
	cont++;
	c.lowcost_parent[0][start_index] = 0;
	last_index = start_index;
	
	for (int i = 0; i < g.vexnum - 1; i++) {
		
		for (int j = 0; j < g.vexnum; j++) {
			if (c.lowcost_parent[0][j] != 0 && g.Edge[last_index][j] < c.lowcost_parent[0][j]) {
				c.lowcost_parent[0][j] = g.Edge[last_index][j];
				c.lowcost_parent[1][j] = last_index;
			}
		}
		int min = MMM;
		int min_index = MMM;
		for (int i = 0; i < g.vexnum; i++) {
			if (c.lowcost_parent[0][i]!=0 && c.lowcost_parent[0][i] < min) {
				min = c.lowcost_parent[0][i];
				min_index = i;
			}
		}
		flag[cont] = min_index;
		cont++;
		c.lowcost_parent[0][min_index] = 0;
		last_index = min_index;
		sum += min;
	}
	cout << sum << endl;
	for (int i = 1; i < cont; i++) {
		int parent = c.lowcost_parent[1][flag[i]];
		cout << g.data[parent] << " " << g.data[flag[i]] << " " << g.Edge[parent][flag[i]] << endl;
	}
}

int main() {
	Graph g;
	string start;
	cin >> start;
	closeEdge c(g, start);
	for (int i = 0; i < g.vexnum; i++) {
		flag[i] = -1;
	}
	Prim(g, c, start);

	return 0;
}
