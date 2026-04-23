#include <iostream>
#define inf 0x3f3f3f

struct maxblk {
  int val, end;
};

int a[1006];
maxblk mxn[1006];

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i];
  
  int k;
  std::cin >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    mxn[i].val = x;
  }
  mxn[0].end = 0;
  a[n+1] = inf;

  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n+1; j++)
      if (a[j] > mxn[i].val) {
        mxn[i].end = j-1;
        break;
      }

  int t;
  std::cin >> t;
  while (t--) {
    int q;
    std::cin >> q;

    int cnt = 0, res = 0;
    bool f = 0;
    int ib;
    for (ib = 1; ib <= k; ib++) {
      cnt++;
      if (q <= mxn[ib].val) break;
    }

    if (ib > k) {
      std::cout << "error\n";
      continue;
    }

    int i;
    for (i = mxn[ib-1].end + 1; i <= mxn[ib].end ;i++) {
      cnt++;
      if (a[i] == q) {
        std::cout << i << '-';
        f = 1;
        break;
      }
    }

    if (f) std::cout << cnt << '\n';
    else std::cout << "error\n";
  }

  return 0;
}
