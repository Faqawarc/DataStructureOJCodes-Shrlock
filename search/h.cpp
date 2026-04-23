#include <iostream>

struct node {
  int val;
  node *l = NULL, *r = NULL;
};

class tree {
  node *root = NULL;
public:
  void insert(int data) {
    node *tmp = new node;
    tmp->val = data;
    if (root == NULL) {
      root = tmp;
      return;
    }

    node *cur = root;
    while (cur) {
      if (cur->val > data) {
        if (cur->l) cur = cur->l;
        else {
          cur->l = tmp;
          return;
        }
      } else {
        if (cur->r) cur = cur->r;
        else {
          cur->r = tmp;
          return;
        }
      }
    }
  }

  void traverse(node *cur) {
    if (cur == NULL) return;
    
    std::cout << cur->val << ' ';
    traverse(cur->l);
    traverse(cur->r);
  }
  
  void forder() {
    traverse(root);
    std::cout << '\n';
  }

};

int main() {
  int n;
  tree tr;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    tr.insert(a);
  }
  tr.forder();

  int m;
  std::cin >> m;
  while (m--) {
    int toinst;
    std::cin >> toinst;
    tr.insert(toinst);
    tr.forder();
  }

  return 0;
}