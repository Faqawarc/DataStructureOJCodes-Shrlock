#include <iostream>

int n;

void qsort(int *arr, int l, int r) {
  int i = l, j = r, k = arr[i];
  while (i < j) {
    while (i < j && arr[j] >= k) j--;
    arr[i] = arr[j];
    while (i < j && arr[i] <= k) i++;
    arr[j] = arr[i];
  }
  arr[i] = k;
  for (int s = 0; s < n; s++)
    std::cout << arr[s] << " \n"[s==n-1];

  if (i-1 > l) qsort(arr, l, i-1);
  if (i+1 < r) qsort(arr, i+1, r);
}


int main() {
  int t;
  std::cin >> t;
  while (t--) {
    n = 0;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      std::cin >> a[i];

    qsort(a, 0, n-1);
    std::cout << '\n';
  }

  return 0;
}
