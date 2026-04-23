#include <iostream>
#include <string>

#define string std::string

class graph {
  int vexnum, arcnum, num;
  bool *vis;
  double **mat;
  string *vex;
  int *path;

  void dfs(int v) {
    vis[v] = 1;
    path[num++] = v;
    for (int i = 0; i < vexnum; i++)
      if (!vis[i] && mat[v][i])
        dfs(i);

  }

  int geti(string s) {
    for (int i = 0; i < vexnum; i++)
      if (vex[i] == s) return i;
    return -1;
  }

  public:
  graph() {
    std::cin >> vexnum >> arcnum;
    vex = new string[vexnum];
    vis = new bool[vexnum];
    mat = new double*[vexnum];
    path = new int[vexnum];

    for (int i = 0; i < vexnum; i++) {
      std::cin >> vex[i];
      mat[i] = new double[vexnum];
      vis[i] = 0;
      path[i] = 0;
      for (int j = 0; j < vexnum; j++)
        mat[i][j] = 0;
    }

    for (int i = 0; i < arcnum; i++) {
      string s1, s2;
      double w;
      std::cin >> s1 >> w >> s2;
      int pos1 = geti(s1);
      int pos2 = geti(s2);
      mat[pos1][pos2] = w;
    }
  }

  void dfss() {
    for (int i = 0; i < vexnum; i++) {
      num = 0;
      dfs(i);
      
      for (int s = 0; s < num; s++) {
        if (mat[path[s]][i]) {
          float res = 1;
          for (int j = 0; j < s; j++)
            res *= mat[path[j]][path[j+1]];
          res *= mat[path[s]][path[0]];

          if (res > 1) {
            std::cout << "YES\n";
            return;
          }
        }
      }
    }
    std::cout << "NO\n";
  }


};

int main() {

  int t;
  std::cin >> t;
  while (t--) {
    graph g;
    g.dfss();
  }

  return 0;
}