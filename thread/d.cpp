#include <iostream>
#include <string>

int gnext(std::string s) {
  int i = 0, k = -1, len=s.length(), mx = -1;
  int next[len+1];
  next[0] = -1;

  while (i < len) {
    if (k == -1 || s[i] == s[k]) {
      i++, k++;
      next[i] = k;
      if (k * 2 <= i) mx = std::max(mx, k);
      if (i / (i-k) >= 2) mx = std::max(mx, (i-k)*(i/(i-k)/2));
    } else k = next[k];
  }
  return mx;
}

void solve() {
  std::string s;
  std::cin >> s;
  int len = s.length(), mx = -1;
  for (int i = 0; i < len; i++) {
    mx = std::max(mx, gnext(s.substr(i, len)));
  }
  std::cout << (mx ? mx : -1) << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
