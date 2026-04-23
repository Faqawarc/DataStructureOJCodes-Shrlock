#include <iostream>
#include <vector>

struct node {
  char data;
  int fa;
  node() {
    data = '0';
    fa = -1;
  }
};

class tree {
  std::vector<node> t;
  int n;
  public:
    tree() {
      std::cin >> n;
      t.resize(n);
      for (int i = 0; i < n; i++) {
        char c;
        std::cin >> c;
        t[i].data=c;
      }
      for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x!=-1) t[i].fa = x;
      }
    }

    void pre(int x = -1) {
      for (int i = 0; i < n ; i++) {
        if (t[i].fa == x) {
          std::cout << t[i].data;
          pre(i);
        }
      }
    }
};

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    tree tr;
    tr.pre();
    std::cout << '\n';
  }
  return 0;
}