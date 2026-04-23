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
    
    for (int iv = n/2; iv >= 1; iv /= 2) {
      for (int i = 0; i < n - iv; i++) {
        for (int j = i + iv; j >= iv; j -= iv) {
          if (a[j] < a[j - iv]) break;
          else {
            int tmp = a[j];
            a[j] = a[j - iv];
            a[j - iv] = tmp;
          }
        }
      }

      for (int i = 0; i < n; i++)
       std::cout << a[i] << " \n"[i==n-1];
    }

    std::cout << '\n';
  }

  return 0;
}