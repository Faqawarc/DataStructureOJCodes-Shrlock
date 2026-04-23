#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
int vexnum;
int arcnum;
int** p;
int BFS(int x) {
	int visited[1005] = { 0 };
	int distance[2005] = { 0 };
	queue<int> q;

	q.push(x);
	visited[x] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 1; i <= vexnum; i++) {
			if (visited[i] == 0 && p[temp][i] == 1) {
				visited[i] = 1;
				distance[i] = distance[temp] + 1;
				q.push(i);
			}
		}
	}
	int num = 0;
	for (int i = 1; i <= vexnum; i++) {
		if (distance[i] >= 1 && distance[i] <= 6) num++;
	}
	return num + 1;
}
void check() {
	for (int i = 1; i <= vexnum; i++) {
		double num=BFS(i);
		double rate = num / vexnum * 100;
		cout << i << ": " << fixed << setprecision(2) << rate << "%" << endl;
	}
}
int main() {
	cin >> vexnum >> arcnum;
	p = new int* [1005];
	for (int i = 0; i < 1005; i++) {
		p[i] = new int[1005]{ 0 };
	}
	for (int i = 0; i < arcnum; i++) {
		int index1, index2;
		cin >> index1 >> index2;
		p[index1][index2] = 1;
		p[index2][index1] = 1;
	}
	check();

	return 0;
}
