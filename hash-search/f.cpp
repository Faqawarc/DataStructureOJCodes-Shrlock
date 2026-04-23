/**
 * binary tree search - avl teen ver.
 * accepted code
 */
#include <iostream>

int height(char *arr, int i) {
  if (arr[i] == '0') return 0;
  return height(arr, i*2+1) > height(arr, i*2+2) ? height(arr, i*2+1) + 1 : height(arr, i*2+2) + 1;
}

void post(char *arr, int i) {
  if (arr[i] == '0') return;
  post(arr, i*2+1);
  post(arr, i*2+2);
  std::cout << arr[i] << ' ' << height(arr, i*2+1) - height(arr, i*2+2) << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, size = 2;
    std::cin >> n;

    while (size < 2*n) size *= 2;
    char arr[size+10];

    for (int i = 0; i < n; i++)
      std::cin >> arr[i];
    for (int i = n; i < size; i++)
      arr[i] = '0';
    post(arr, 0);
  }
  return 0;
}