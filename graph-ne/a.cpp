#include <iostream>
#include <vector>

#define MX 1001
#define inf 0x3f3f3f3f

class graph {
  int mat[MX][MX];
  int dist[MX] = {0};
  int vexnum;
  std::string vex[MX];
  std::vector<int> path[MX];
  std::string start;
  bool done[MX] = {0};
public:
  graph() {
    std::cin >> vexnum;
    for (int i = 0; i < vexnum; i++) std::cin >> vex[i];
    for (int i = 0; i < vexnum; i++)
      for (int j = 0; j < vexnum; j++)
        std::cin >> mat[i][j];
    std::cin >> start;
  }

  void dijst() {
    int si = geti(start);
    for (int j = 0; j < vexnum; j++)
      if (mat[si][j]) {
        dist[j] = mat[si][j];
        path[j].push_back(si);
        path[j].push_back(j);
      }
    
    done[si] = 1;

    for (int i = 0; i < vexnum-1; i++) {
      int mindist = inf;
      int mini;
      for (int j = 0; j < vexnum; j++)
        if (!done[j] && dist[j] && dist[j] < mindist) {
          mini = j;
          mindist = dist[j];
        }
      done[mini] = 1;

      for (int j = 0; j < vexnum; j++)
        if (mat[mini][j] && !done[j] && (mindist + mat[mini][j] < dist[j] || !dist[j])) {
          dist[j] = mindist+mat[mini][j];
          path[j] = path[mini];
          path[j].push_back(j);
        }
    }
  }

  int geti(std::string &data) {
    for (int i = 0; i < vexnum; i++)
      if (vex[i] == data) return i;
  }

  void print() {
    dijst();
    for (int i = 0; i < vexnum; i++) {
      if (i == geti(start)) continue;

      if (dist[i]) {
        std::cout << start << '-' << vex[i] << '-' << dist[i] << "----[";
        for (auto& it:path[i]) std::cout << vex[it];
        std::cout << "]\n";
      } else std::cout << start << '-' << vex[i] << "--1\n";
    }
  }

};

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    graph g;
    g.print();
  }

  return 0;
}