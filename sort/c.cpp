#include <iostream>

int bublsort(int *arr, int n) {
  int cnt = 0;
  for (int i = n-1; i >= 0; i--)
    for (int j = 0; j < i; j++)
      if (arr[j] > arr[j+1]) {
        cnt++;
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }

  return cnt;
}

int main() {
  int n;
  while (std::cin >> n) {
    int arr[n];
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    std::cout << bublsort(arr, n) << '\n';
  }
  return 0;
}