#include <iostream>

struct node {
  int val;
  node *l=NULL, *r=NULL;
};

class tree {
  node *root = NULL;
public:
  void insert(int data) {
    node *tmp = new node;
    tmp->val = data;
    if (root==NULL) {
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

  void find(int data) {
    int cnt = 0;
    node *cur = root;
    while (cur) {
      cnt++;
      if (cur->val == data) {
        std::cout << cnt << '\n';
        return;
      } else if (cur->val < data) {
        if (cur->r) cur = cur->r;
        else {
          std::cout << "-1\n";
          return;
        }
      } else {
        if (cur->l) cur = cur->l;
        else {
          std::cout << "-1\n";
          return;
        }
      }
    }
  }

  void traverse(node *cur) {
    if (cur==NULL) return;
    traverse(cur->l);
    std::cout << cur->val << ' ';
    traverse(cur->r);
  }

  void display() {
    traverse(root);
    std::cout << '\n';
  }

};

int main() {
  int n;
  std::cin >> n;
  tree tr;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    tr.insert(a);
  }
  tr.display();

  int q;
  std::cin >> q;
  while (q--) {
    int a;
    std::cin >> a;
    tr.find(a);
  }
  return 0;
}