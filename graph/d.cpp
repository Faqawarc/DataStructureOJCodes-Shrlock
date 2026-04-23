#include <iostream>
#include <vector>
#include <queue>

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
  std::queue<int> qe;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    qe.push(i);
    while (!qe.empty()) {
      int t = qe.front();
      qe.pop();
      if (vis[t])continue;
      vis[t] = 1;
      std::cout << t << ' ';
      for (int j = 0; j < n; j++) {
        if (graph[t][j] && !vis[j]) qe.push(j);
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