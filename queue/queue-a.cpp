#include <iostream>
#include <queue>

int main() {
  int n;
  std::queue<int> q[3];
  std::cin >> n;
  char tmp[n];
  for (int i = 0; i < n; i++) {
    std::cin >> tmp[i];
  }

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    switch (tmp[i]) {
      case 'A': q[0].push(a);
      break;
      case 'B': q[1].push(a);
      break;
      case 'C': q[2].push(a);
      break;
    }
  }

  int avg[3] = {0}, cnt = 0;
  for (int f = 0; f < 3; f++) {
    cnt = 0;
    while (!q[f].empty()) {
      avg[f] += q[f].front();
      q[f].pop();
      cnt++;
    }
    avg[f] /= cnt;
    std::cout << avg[f] << '\n';
  }



  return 0;
}