/**
 * 链地址 - 表头插入
 * accepted code
 */
#include <iostream>

struct node {
  int val;
  node *next;
};

node *arr[11];

void hashadd(int val) {
  node *p = new node;
  p->val = val;
  p->next = arr[val%11];
  arr[val%11] = p;
}

int main() {
  int n;
  std::cin >> n;
  while (n--) {
    int a;
    std::cin >> a;
    hashadd(a);
  }

  int t;
  std::cin >> t;
  while (t--) {
    int q;
    std::cin >> q;
    node *p = arr[q%11];
    int cnt = 1;
    while (p) {
      if (p->val == q)break;
      p = p->next;
      cnt++;
    }
    if (p) std::cout << q%11 << ' ' << cnt << '\n';
    else {
      std::cout << "error\n";
      hashadd(q);
    }
  }
  return 0;
}