/*
   this code isn't accepted
*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int mat[n][n];

    for (int i = 0; i < n; i++) 
      for (int j = 0; j < n; j++)
        std::cin >> mat[i][j];

    int fl = 0;
    int vis[150] = {0};
    int s = n;
    while (s--) {
      for (int i = 0; i < n; i++) {
        int ig = 0;
        for (int j = 0; j < n; j++) {
          ig += mat[j][i];
        }

        if (ig==0 && vis[i]==0) {
          vis[i] = 1;
          if (fl==0) {
            fl = 1;
            std::cout << i << ' ';
          } else std::cout << i << ' ';
          for (int j = 0; j < n; j++) if (mat[i][j] > 0) mat[i][j]--;
        }
      }
    }
    std::cout << '\n';
  }
  return 0;
}