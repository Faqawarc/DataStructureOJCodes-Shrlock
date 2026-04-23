#include <iostream>
#include <algorithm>
using namespace std;

string vex[205];
int vexnum;
int arcnum;
int tag[205];
int visited[205] = { 0 };

struct Node {
	int weight;
	string v1;
	string v2;
};

struct compareNode {
	bool operator()(Node& n1, Node& n2) {
		return n1.weight < n2.weight;
	}
};

int get_index(string s) {
	for (int i = 0; i < vexnum; i++) {
		if (s == vex[i]) return i;
	}
	return -1;
}

void Kruskal(Node arr[]) {
	int sum = 0;
	int num = 0;
	
	int flag[205];
	int cont = 0;
	
	int cont2 = 0;
	while (arcnum--) {
		int weight = arr[cont2].weight;
		string v1 = arr[cont2].v1;
		string v2 = arr[cont2].v2;

		int index1 = get_index(v1);
		int index2 = get_index(v2);
		
		if (tag[index1] != tag[index2]) {
			num++;
			sum += weight;
			
			int temp = tag[index2];
			for (int i = 0; i < vexnum; i++) {
				if (tag[i] == temp) {
					tag[i] = tag[index1];
				}
			}
			flag[cont] = cont2;
			cont++;
		}
		cont2++;
	}
	if (num == vexnum - 1) {
		cout << sum << endl;
		for (int i = 0; i < cont; i++) {
			if (get_index(arr[flag[i]].v1) < get_index(arr[flag[i]].v2)) {
				cout << arr[flag[i]].v1 << " " << arr[flag[i]].v2 << " " << arr[flag[i]].weight << endl;
			} else {
				cout << arr[flag[i]].v2 << " " << arr[flag[i]].v1 << " " << arr[flag[i]].weight << endl;
			}
		}
	} else {
		cout << "-1" << endl;
	}
}
int main() {
	
	cin >> vexnum;
	for (int i = 0; i < vexnum; i++) {
		cin >> vex[i];
	}
	
	cin >> arcnum;
	Node arr[205];
	for (int i = 0; i < arcnum; i++) {
		cin >> arr[i].v1 >> arr[i].v2 >> arr[i].weight;
	}
	
	sort(arr, arr + arcnum, compareNode());

	for (int i = 0; i < vexnum; i++) {
		tag[i] = i;
	}
	Kruskal(arr);

	return 0;
}
