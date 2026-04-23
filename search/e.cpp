#include <iostream>


int main() {
  int n;
  std::cin >> n;
  int a[n], b[n], c[2*n];

  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  for (int i = 0; i < n; i++)
    std::cin >> b[i];

  int i = 0, j = 0, k = 0;
  while (i < n && j < n) {
    if (a[i] <= b[j]) c[k++] = a[i++];
    else c[k++] = b[j++];
  }
  while (i < n) c[k++] = a[i++];
  while (j < n) c[k++] = b[j++];

  std::cout << c[n-1];
  return 0;
}