#include <iostream>

int st[10005];

int search(int l, int r, int q) {
  int mid = (r+l)/2;
  if (st[mid] == q) return mid;
  else if (l == r || l > r || r < l) return 0;
  else if (st[mid] > q) return search(l, mid-1, q);
  else if (st[mid] < q) return search(mid+1, r, q);
  return 0;
}

int main() {
  int n, t;
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> st[i];

  std::cin >> t;
  while (t--) {
    int q;
    std::cin >> q;
    int res = search(1, n, q);
    if (res) std::cout << res << '\n';
    else std::cout << "error\n";
  }

  return 0;
}