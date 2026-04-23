#include <iostream>
#include <stack>
#include <queue>

const char numf[16] = {
  '0', '1', '2', '3', '4', '5',
  '6', '7', '8', '9', 'A', 'B',
  'C', 'D', 'E', 'F'
};

void solution() {
  double x;
  int k;
  std::cin >> x >> k;

  std::queue<char> frac;
  std::stack<char> itgr;
  std::string integer;
  std::string fraction;

  int itg = x;
  x -= itg;

  // integer part
  while (itg != 0) {
    char t = numf[itg%k];
    itgr.push(t);
    itg /= k;
  }
  if (itgr.top() == '0') itgr.push('1');
  while (!itgr.empty()) {
    integer += itgr.top();
    itgr.pop();
  }

  // fraction part
  int y = 3;
  while (y--) {
    char t = numf[(int)(x*k)];
    frac.push(t);
    x *= k;
    if (x > 1) {
      int tmp = x;
      x -= tmp;
    }
  }

  while (!frac.empty()) {
    fraction += frac.front();
    frac.pop();
  }

  std::cout << integer << '.' << fraction << '\n';


}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}