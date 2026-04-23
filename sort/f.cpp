
#include <iostream>

int a[10001], n;
bool vis[10010];
int main() {
  int cnt = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  
  for (int i = 0; i < n; i++) {
    if (!vis[i] && a[i] != i) {
      bool f = 0;
      int t = i, tmp = 0;
      while (!vis[t]) {
        if (a[t] == 0) f = 1;
        vis[t] = 1;
        t = a[t];
        tmp++;
      }
      if (f) cnt += tmp - 1;
      else cnt += tmp + 1;
    }
    else vis[i] = 1;
  }

  std::cout << cnt;
  return 0;
}