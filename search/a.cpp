#include <iostream>

struct seq {
  int wrr, val;
};

seq a[10005];

int search(int t, int n) {
  int i = 0;
  a[i].wrr = t;
  for (i = n; a[i].val != t && a[i].wrr != t; i--);
  return i;
}

int main() {
  int n, t;
  std::cin >> n;
  for (int i = 1; i <= n ; i++) {
    std::cin >> a[i].val;
  }
  std::cin >> t;
  while (t--) {
    int qs;
    std::cin >> qs;
    int res = search(qs, n);
    if (res) std::cout << res << '\n';
    else std::cout << "error\n";
  }

  return 0;
}