#include <iostream>
#include <iomanip>

int cnt;

double binary(double l, double r, double trg) {
  double mid = (l+r)/2;
  double eps = 1e-5;
  while (r-l >= eps) {
    cnt++;
    mid = (l+r)/2;
    if (mid*mid > trg) r = mid;
    else l = mid;
  }
  return l;
}

int main() {
  int n;
  std::cin >> n;
  while (n--) {
    int a;
    cnt = 1;
    std::cin >> a;
    double res = binary(0, a, a);
    std::cout << cnt << ' ' << std::fixed << std::setprecision(3) << res << '\n';
  }
  return 0;
}