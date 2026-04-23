#include <iostream>
#include <queue>

struct gd {
  char gr;
  int id;
};

int main() {
  std::string line;
  std::cin >> line;
  int s = line.length();
  std::queue<gd> a, d;
  char b = line[0];
  char g;
  for (int i = 0; i < s; i++) {
    if (line[i] != b) {
      g = line[i];
      break;
    }
  }

  int cnt = 0;
  for (int i = 0; i < s; i++) {
    a.push({line[i], cnt++});
  }
  
  gd fst, sec;
  while (!a.empty()) {
    fst = a.front();
    a.pop();
    sec = a.front();
    if (fst.gr == b && sec.gr == g) {
      a.pop();
      std::cout << fst.id << ' ' << sec.id << '\n';
      while (!a.empty()) {
        d.push(a.front());
        a.pop();
      }
      while (!d.empty()) {
        a.push(d.front());
        d.pop();
      }
    } else {
      d.push(fst);
    }
  }
}