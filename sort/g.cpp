#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      std::cin >> a[i];
    
    for (int i = 0; i < n-1; i++) {
      int m = a[i], mi = i;
      for (int j = i+1; j < n; j++) {
        if (m > a[j]) {
          m = a[j];
          mi = j;
        }
      }
      a[mi] = a[i];
      a[i] = m;
      for (int s = 0; s < n; s++) std::cout << a[s] << " \n"[s==n-1];
    }
    std::cout << '\n';
  }

  return 0;

}