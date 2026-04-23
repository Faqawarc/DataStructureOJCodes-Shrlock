#include <iostream>
#include <queue>

int main() {
  int n;
  std::cin >> n;
  std::queue<int> a, b;
  for (int i = 0; i < n ;i++) {
    int tmp;
    std::cin >> tmp;
    if (tmp % 2) {
      a.push(tmp);
    } else {
      b.push(tmp);
    }
  }

  while (!a.empty() && !b.empty()) {
    std::cout << a.front() << ' ';
    a.pop();
    if (a.empty()) break;
    std::cout << a.front() << ' ';
    a.pop();
    std::cout << b.front() << ' ';
    b.pop();
  }

  while (!a.empty()) {
    std::cout << a.front() << ' ';
    a.pop();
  }

  while (!b.empty()) {
    std::cout << b.front() << ' ';
    b.pop();
  }


  return 0;
}