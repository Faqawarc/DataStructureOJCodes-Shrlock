#include<iostream>
#include<vector>
#include<map>
using namespace std;

class graph {
	int n, k;
	vector<int>h;
	vector<int>ne;
	vector<int>e;
	int idx;
	map<char, int>id;
	vector<char>value;
public:
	graph() {
		idx = 0;
		cin >> n >> k;
		h.resize(2 * n, -1);
		ne.resize(2 * n);
		e.resize(2 * n);
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
		    id[c] = i;
			value.push_back(c);
		}
		for (int i = 0; i < k; i++) {
			char u, v;
			cin >> u >> v;
			add(id[u], id[v]);
		}
	}
	void add(int a, int b) {
		e[idx] = b;
		ne[idx] = h[a];
		h[a] = idx++;
	}
	void show() {
		for (int i = 0; i < n; i++) {
			cout << i << " " << value[i] << "-";
			vector<int>ans;
			for (int j = h[i]; ~j; j = ne[j]) {
				int k = e[j];
				ans.push_back(id[value[k]]);
			}
			for (int i=ans.size()-1;i>=0;i--) {
				cout << ans[i] << "-";
			}
			cout << "^" << endl;
		}
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		graph g;
		g.show();
	}
	return 0;
}