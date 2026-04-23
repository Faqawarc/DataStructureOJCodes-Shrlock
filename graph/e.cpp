#include <iostream>
#define inf 0x3f3f3f3f

long long res;
int graph[1001][1001];

void brutefore(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }
}

int main() {
  int n, m, k;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) graph[i][j] = 0;
      else graph[i][j] = inf;
    }
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    graph[u][v] = graph[v][u] = 1;
  }
  brutefore(n);
  std::cin >> k;

  bool flag = 0;
  for (int i = 0; i < k; i++) {
    res = 0;
    int query;
    std::cin >> query;
    if (!flag) {
      for (int j = 1; j <= n; j++) {
        if (query == j) continue;
        if (graph[query][j] > inf / 2) {
          flag = 1;
          break;
        }
        res += graph[query][j];
      }
    }

    if (flag) std::cout << "Cc(" << query << ")=0.00\n";
    else {
      double ans = (double)(n-1) / res;
      printf("Cc(%d)=%.2f\n", query, ans);
    }
  }
  return 0;

}