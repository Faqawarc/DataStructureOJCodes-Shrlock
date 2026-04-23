#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int *prt = new int[n];
  int *chdnum = new int[n];
  char *nd = new char[n];
  int **prt_chd = new int*[n];

  for (int i = 0; i < n; i++) {
    std::cin >> nd[i];
    prt_chd[i] = new int[n];
    chdnum[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> prt[i];
    if (prt[i] != -1) {
      prt_chd[prt[i]][chdnum[prt[i]]++] = i;
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << nd[i] << ' ';

    if (chdnum[i]) {
      for (int j = 0; j < chdnum[i]; j++) {
        std::cout << prt_chd[i][j] << ' ';
      }
    } else {
      std::cout << "-1 ";
    }

    std::cout << '\n';

  }
  return 0;
}