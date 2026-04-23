#include <iostream>
#define mx (int)1e6

struct node {
  int x, y;
};

bool done, vis[mx];
node nd[mx];
int n, d;

bool first(int v) {
  return nd[v].x*nd[v].x + nd[v].y*nd[v].y <= (d+7.5)*(d+7.5);
}

bool canjump(int i, int j) {
  int p1 = (nd[i].x - nd[j].x) * (nd[i].x - nd[j].x);
  int p2 = (nd[i].y - nd[j].y) * (nd[i].y - nd[j].y);
  if (p1 + p2 <= d*d) return 1;
  return 0;
}

bool out(int pos) {
  return (nd[pos].x-d<=-50 || nd[pos].y-d<=-50 || nd[pos].x+d>=50 || nd[pos].y+d>=50);
}

void dfs(int v) {
  vis[v] = 1;
  if (out(v)){
    done = 1;
    return;
  }

  for (int i = 0; i < n; i++)
    if (!vis[i] && canjump(v, i))
      dfs(i);

}

int main() {
  std::cin >> n >> d;

  for (int i = 0; i < n; i++)
    std::cin >> nd[i].x >> nd[i].y;

  if (d >= 50) {
    std::cout << "Yes\n";
    return 0;
  }

  for (int i = 0; i < n; i++)
    if (!vis[i] && first(i))
      dfs(i);
  
  if (done) std::cout << "Yes\n";
  else std::cout << "No\n";

  return 0;

}