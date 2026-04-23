#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

int n, vn, k, v;
int c[1000][2], vip[1000], vis[1000];
int tt[10], num[10], t, at, cnt;

struct cmp {
  bool operator() (const int &a, const int &b) const {
    if (tt[a] == tt[b])
      return b == v || a != v && a > b;
    return tt[a] > tt[b];
  }
};

int main() {
  int isvip;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> c[i][0] >> c[i][1] >> isvip;
    if (c[i][1] > 60) c[i][1] = 60;
    if (isvip) vip[vn++] = i;
  }

  std::cin >> k >> v;
  std::priority_queue<int, std::vector<int>, cmp> pq;

  for (int i = 0; i < k; i++) {
    pq.push(i);
  }

  int j = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    int ii = i, ivip = 0;
    while (tt[pq.top()] < c[i][0]) {
      int d = pq.top();
      pq.pop();
      tt[d] = c[i][0];
      pq.push(d);
    }
    int d = pq.top();
    pq.pop();

    if (j < vn && i == vip[j]) j++, ivip = 1;
    else if (d == v && j < vn && (c[i][0] == c[vip[j]][0] || c[vip[j]][0] < tt[d])) {
        ii = vip[j++];
        ivip = 1;
        vis[ii] = 1;
        i--;
    }

    if (!ivip && !pq.empty() && pq.top() < d && tt[pq.top()] == tt[d]) {
      int e = pq.top();
      pq.pop();
      pq.push(d);
      d = e;
    }

    num[d]++;

    if (tt[d] > c[ii][0]) {
      t += tt[d] - c[ii][0];
      at = std::max(at, tt[d] - c[ii][0]);
    }

    tt[d] = std::max(tt[d], c[ii][0]) + c[ii][1];
    cnt = std::max(cnt, tt[d]);
    pq.push(d);
  }

  printf("%.1f %d %d\n", t * 1.0 / n, at, cnt);
  for (int i = 0; i < k; i++) {
    if (i) putchar(' ');
    printf("%d", num[i]);
  }

  return 0;
}