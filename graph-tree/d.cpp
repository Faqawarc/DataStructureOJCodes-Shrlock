#include <iostream>
using namespace std;
int vexnum;
int arcnum;
int test_num;
int test_path[205];
int** p;
int visited[205] = { 0 };
void check() {
	if (test_path[0] <= vexnum) {
		cout << "NO" << endl;
		return;
	}
	visited[test_path[1]]++;
	int len = test_path[0];
	int index1, index2;
	for (int i = 1; i <= len-1; i++) {
		index1 = test_path[i];
		index2 = test_path[i + 1];
		
		if (p[index1][index2]!=1) {
			cout << "NO" << endl;
			return;
		}
		visited[index2]++;
	}
	
	if (visited[test_path[1]] != 2) {
		cout << "NO" << endl;
		return;
	}
	for (int i = 2; i <= vexnum; i++) {
		if (i != test_path[1]) {
			if (visited[i] != 1) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}
int main() {
	cin >> vexnum >> arcnum;
	p = new int* [205];
	for (int i = 0; i < 205; i++) {
		p[i] = new int[205]{ 0 };
	}
	int index1, index2;
	for (int i = 0; i < arcnum; i++) {
		cin >> index1 >> index2;
		p[index1][index2] = 1;
		p[index2][index1] = 1;
	}
	cin >> test_num;
	for (int i = 0; i < test_num; i++) {
		cin >> test_path[0];
		for (int i = 1; i <= test_path[0]; i++) {
			cin >> test_path[i];
		}
		check();
	}
	return 0;
}