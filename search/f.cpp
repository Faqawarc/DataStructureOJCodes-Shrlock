#include <iostream>

struct node {
  int val;
  node* next = NULL;
};

int main() {
  int n;
  std::cin >> n;

  node* list = new node;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    node *pt = list;
    node *th = new node;
    int da;
    std::cin >> da;
    th->val = da;

    while (1) {
      if (pt->next==NULL) {
        pt->next = th;
        break;
      }
      if (pt->next->val > da) {
        th->next = pt->next;
        pt->next = th;
        cnt++;
        break;
      }
      pt = pt->next;
    }
  }

  std::cout << "非空指针变化" << cnt << "次\n";
  list = list->next;
  node* pt = list;
  for (int i = 0; i < n; i++) {
    std::cout << pt->val << " \n"[i==n-1];
    pt = pt->next;
  }

  int m;
  std::cin >> m;
  while (m--) {
    int q;
    std::cin >> q;
    if (q>n||q<1) {
      std::cout << "error\n";
      continue;
    }

    pt = list;
    q--;
    while (q--) {
      pt = pt->next;
    }
    std::cout << pt->val << '\n';
  }

  return 0;
}