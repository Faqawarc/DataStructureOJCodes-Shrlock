/**
 * hash address search - insert tail of linked list
 * accepted code
 */
#include <iostream>

struct node {
  int val;
  node *next;
  node() {}
  node(int n, node *nx):val(n), next(nx){}
};

node *arr[101];

int hash(int key) {
  return key % 11;
}

void hashadd(int val) {
  node *ti = new node(val, NULL);
  node *p = arr[hash(val)];
  if (p == NULL) {
    arr[hash(val)] = ti;
    return;
  }

  while (p->next) {
    p = p->next;
  }
  p->next = ti;
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
    node *p = arr[hash(q)];
    int cnt = 1;
    while (p) {
      if (p->val == q)break;
      p = p->next;
      cnt++;
    }
    if (p) std::cout << hash(q) << ' ' << cnt << '\n';
    else {
      std::cout << "error\n";
      hashadd(q);
    }
  }
  return 0;
}