#include <iostream>

void order(int i, int *a) {
  if (a[i]) {
    std::cout << a[i] << ' ';
    order(2*i, a);
    order(2*i+1, a);
  }
}

void solve() {
  int n, a[100010] = {0};
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  order(1, a);
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}