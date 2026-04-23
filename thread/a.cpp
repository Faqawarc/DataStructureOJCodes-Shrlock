#include <iostream>
#include <string>


void get_next(std::string str, int *next) {
  int j = 1, k = 0;
  next[1] = 0;
  int len = str.length() - 1;
  while (j<len) {
    if (k==0 || str[j] == str[k]) {
      ++j;
      ++k;
      next[j] = k;
    } else k = next[k];
  }

}

void solve() {
  std::string line, cat, rep;
  std::cin >> line >> cat >> rep;
  line = "#" + line;
  cat = "#" + cat;

  int pos = -1;
  int next[1001];
  get_next(cat, next);

  int i = pos, j = 1;
  int ll = line.length(), cl = cat.length();
  while (i < ll && j < cl) {
    if (j==0 || line[i] == cat[j]) {
      ++i;
      ++j;
    } else j = next[j];
  }
  if (j > cl-1) pos = i-cl+1;

  std::cout << line.substr(1, ll-1) << '\n';
  if (pos > 0) {
    std::string after = line.substr(1, pos-1) + rep + line.substr(pos-1+cl);
    std::cout << after << '\n';
  } else {
    std::cout << line.substr(1, ll-1) << '\n';
  }

}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}