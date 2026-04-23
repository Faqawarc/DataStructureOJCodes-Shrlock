#include <iostream>

void print(int *a, int n) {
  std::cout << n << ' ';
  for (int i = 0; i < n; i++)
    std::cout << a[i] << " \n"[i==n-1];
}

void adj(int *a, int i, int n) {
  while (2*i+1 < n) {
    int k = 2*i+1;
    if (k+1 < n && a[k+1] < a[k]) k++;
    if (a[i] > a[k]) {
      int tmp = a[i];
      a[i] = a[k];
      a[k] = tmp;
      i = k;
    } else break;
  }
}

void heapsort(int *a, int n) {
  for (int i = n/2; i >= 0; i--)
    adj(a, i, n);
  print(a, n);
  for (int i = 1; i < n; i++) {
    int tmp = a[0];
    a[0] = a[n-i];
    a[n-i] = tmp;
    adj(a, 0, n-i);
    print(a, n);
  }
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  heapsort(a, n);
  return 0;
}