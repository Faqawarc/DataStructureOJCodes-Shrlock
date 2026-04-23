/*
#include <iostream>
#include <string>

int* gnext(std::string str) {
  int len = str.length();
  int *next = new int[len+1];
  int j = 0, k = -1;
  next[j] = k;
  while (j<len) {
    if (k==-1 || str[j] == str[k]) {
      ++j;
      ++k;
      next[j] = k;
    } else k = next[k];
  }
  return next;
}

int kpmi(std::string m, std::string pat) {
  int j = 0, k = 0;
  int *next = gnext(pat);
  while (j < m.length() && k < pat.length()) {
    if (k==-1 || m[j] == pat[k])
      j++, k++;
    else
      k = next[k];
  }
  if (k == pat.length())
    return j - k + 1;
  else
    return 0;

}

int count(std::string m, std::string pat) {
  int mlen = m.length(), plen = pat.length(), cnt = 0, ix;
  std::string str = m;
  while (1) {
    if (kpmi(str, pat) != 0) {
      ix = kpmi(str, pat);
      cnt++;
      str = str.substr(ix, mlen);
    } else {
      break;
    }
  }
  return cnt;

}

void solve() {
  std::string str;
  int n;
  std::cin >> str >> n;
  std::string pat[n];
  for (int i = 0; i < n; i++) {
    std::cin >> pat[i];
    std::cout << pat[i] << ':' << count(str, pat[i]) << '\n';
  }
}

int main() {
  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}

*/

#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string str;
    int n;
    std::cin >> str >> n;
    while (n--) {
      std::string q;
      std::cin >> q;
      int cnt = 0, pos = 0;
      while (str.find(q, pos) != std::string::npos) {
        cnt++;
        pos = str.find(q, pos);
        pos++;
      }
      std::cout << q << ':' << cnt << '\n';
    }
  }
}