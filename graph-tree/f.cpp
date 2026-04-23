#include <iostream>
#include <queue>
using namespace std;
int vexnum;
int vex[505];
int arcnum;
int** p;
int lost_vexnum;
int lost_vex[505];
int last_flag=1;
int current_flag=1;
void BFS(int x) {
	
	current_flag = 1;
	int visited[205] = { 0 };
	queue<int> q;
	q.push(x);
	visited[x] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0; i < vexnum; i++) {
			if (p[temp][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	for (int i = 0; i < vexnum; i++) {
		
		if (visited[i] == 0 && vex[i] != -1) {
			current_flag = 0;
			break;
		}
	}
}
int main() {
	
	cin >> vexnum >> arcnum;
	for (int i = 0; i < vexnum; i++) {
		vex[i] = i;
	}
	p = new int* [505];
	for (int i = 0; i < 505; i++) {
		p[i] = new int[505];
	}
	for (int i = 0; i < arcnum; i++) {
		int index1, index2;
		cin >> index1 >> index2;
		p[index1][index2] = 1;
		p[index2][index1] = 1;
	}
	
	BFS(0);
	last_flag = current_flag;
	
	cin >> lost_vexnum;
	for (int i = 0; i < lost_vexnum; i++) {
		cin >> lost_vex[i];
	}
	
	for (int i = 0; i < lost_vexnum; i++) {
		
		vex[lost_vex[i]] = -1;
		for (int j = 0; j < vexnum; j++) {
			p[lost_vex[i]][j] = 0;
		}
		
		BFS(lost_vex[lost_vexnum - 1]);
		if (last_flag ==1&&current_flag==0) {
			cout << "Red Alert: City " << lost_vex[i] << " is lost!" << endl;
		} else {
			cout << "City " << lost_vex[i] << " is lost." << endl;
		}
		last_flag = current_flag;
	}
	if (vexnum - lost_vexnum == 0) {
		cout << "Game Over." << endl;
	}

	return 0;
}
