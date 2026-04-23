#include <iostream>
#include <string>

std::string matched_Prefix_Postfix(std::string str) {

  int len = str.length();
  if (len == 1) return "empty";
  int k = 0, i;

  for (i = len-1; i > 0; i--) {
    std::string t1, t2;
    t1 = str.substr(0, i);
    t2 = str.substr(len-i, i);
    if (t1==t2) {
      k = 1;
      break;
    }
  }

  if (k) return str.substr(0, i);
  else return "empty";

}

void solve() {
  std::string str;
  std::cin >> str;
  std::cout << matched_Prefix_Postfix(str) << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}