/**
 * insert sort
 * accepted code
 * 
 */
#include <iostream>

void isort(int *arr, int n) {
  int i, j, tmp;

  for (i = 1; i < n; i++) {
    tmp = arr[i];
    for (j = i-1; j >= 0 && arr[j] > tmp; j--) arr[j+1] = arr[j];
    arr[j+1] = tmp;

    for (int s = 0; s < n; s++)
      std::cout << arr[s] << " \n"[s==n-1];
  }
}

int main() {
  int n;
  std::cin >> n;
  int arr[n+10];
  for (int i = 0; i < n; i++) std::cin >> arr[i];
  isort(arr, n);
  return 0;
}