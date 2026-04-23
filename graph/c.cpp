#include <iostream>
#include <vector>
#include <stack>

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      std::cin >> a;
      graph[i].push_back(a);
    }
  }
  std::vector<int> vis(n);
  std::stack<int> sk;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    sk.push(i);
    while (!sk.empty()) {
      int t = sk.top();
      sk.pop();
      if (vis[t])continue;
      vis[t] = 1;
      std::cout << t << ' ';
      for (int j = n-1; j >= 0; j--) {
        if (graph[t][j] && !vis[j]) sk.push(j);
      }
    }
  }
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}