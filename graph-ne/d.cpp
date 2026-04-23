#include <iostream>

#define inf 0x3f3f3f3f
#define mx (int)1e6

int n, m, s, d, cnt;
int dst[mx], h[mx], to[mx], val[mx], nxt[mx], spd[mx], cot[mx];
bool vis[mx];

#define add(u, v, w, x) do { \
  to[++cnt] = v; \
  val[cnt] = w; \
  spd[cnt] = x; \
  nxt[cnt] = h[u];\
  h[u] = cnt; \
} while(0)


/*

  important part

*/
void dijkstra() {
  for (int i = 1; i <= n; i++)
    dst[i] = inf;
  dst[s] = 0;
  dst[0] = inf;

  while(1){
    int u = 0;
    for(int i=1; i<=n; i++)
      if(!vis[i] && dst[u] > dst[i]) u = i;

    if(u == 0) break;
    vis[u] = 1;

    for(int i = h[u]; i; i = nxt[i])
      if(dst[to[i]] > dst[u] + val[i]){
        cot[to[i]] = cot[u] + spd[i];
        dst[to[i]] = dst[u] + val[i];
      }
      else if(dst[to[i]] == dst[u] + val[i])
        cot[to[i]] = std::min(cot[to[i]], cot[u] + spd[i]);
  }
}

int main() {
  std::cin >> n >> m >> s >> d;
  s++, d++;

  for (int i = 1, u, v, w, x; i <= m; i++) {
    std::cin >> u >> v >> w >> x;
    add(u+1, v+1, w, x);
    add(v+1, u+1, w, x);
  }
  dijkstra();
  std::cout << dst[d] << ' ' << cot[d];
  return 0;
}