#include <iostream>
#include <queue>

#define MX 510

bool vis[MX];

struct graph {
  std::string vex[MX];
  int mat[MX][MX];
  int vexnum, arcnum, res;
  graph() {
    for (int i = 0; i < MX; i++)
      for (int j = 0; j < MX; j++)
        mat[i][j] = 0;
    res = 0;

    std::cin >> vexnum;
    for (int i = 0; i < vexnum; i++) {
      std::cin >> vex[i];
    }

    std::cin >> arcnum;
    std::string st, ed;
    int sti, edi;
    for (int i = 0; i < arcnum; i++) {
      std::cin >> st >> ed;
      sti = getindex(st);
      edi = getindex(ed);
      mat[sti][edi] = mat[edi][sti] = 1;
    }
  }

  int getindex(std::string c) {
    for (int i = 0; i < vexnum; i++)
      if (vex[i] == c) return i;
    return -1;
  }

  int findst(int x) {
    for (int i = 0; i < vexnum; i++)
      if (mat[x][i] == 1) return i;
    return -1;
  }

  int findnx(int x, int w) {
    for (int i = w + 1; i < vexnum; i++)
      if (mat[x][i] == 1) return i;
    return -1;
  }

  void bfs(int a) {
    std::queue<int> q;
    q.push(a);
    vis[a] = 1;
    while (!q.empty()) {
      int tmp = q.front();
      q.pop();
      for (int w = findst(tmp); w >= 0; w = findnx(tmp, w))
        if (!vis[w]) {
          vis[w] = 1;
          q.push(w);
        }
    }
  }

  void bfss() {
    for (int i = 0; i < vexnum; i++) {
      if (!vis[i]) {
        bfs(i);
        res++;
      }
    }
  }

  void print() {
    for (int i = 0; i < vexnum; i++)
      std::cout << vex[i] << " \n"[i==vexnum-1];
    for (int i = 0; i < vexnum; i++)
      for (int j = 0; j < vexnum; j++)
        std::cout << mat[i][j] << " \n"[j==vexnum-1];
    std::cout << res << '\n';
  }
};

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    graph g;
    for (int i = 0; i < MX; i++) {
      vis[i] = 0;
    }
    g.bfss();
    g.print();
    std::cout << '\n';
  }
  return 0;
}