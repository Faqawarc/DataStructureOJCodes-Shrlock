#include <iostream>

struct node {
  char d;
  int child[20];
};

void play(node tr[], int r) {
  for (int i = 0; tr[r].child[i] != -1; i++) play(tr, tr[r].child[i]);
  std::cout << tr[r].d;
}

int main() {
  int n, r;
  std::cin >> n >> r;
  node tr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> tr[i].d;
    for (int j = 0;; j++) {
      std::cin >> tr[i].child[j];
      if (tr[i].child[j] == -1) break;
    }
  }
  play(tr, r);
  return 0;
}