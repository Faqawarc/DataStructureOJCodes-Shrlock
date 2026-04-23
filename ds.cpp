#include <iostream>

struct node {
  char data;
  node *l = NULL, *r = NULL;
};

node *create(std::string pre, int pi, int pj, std::string mid, int mi, int mj) {

  node *t = new node();
  t->data = pre[pi];
  int cr = mi; // cr for index of current root*
  while (pre[pi] != mid[cr]) cr++;

  if (cr == mi) t->l = NULL;
  else t->l = create(pre, pi+1, cr-mi+pi, mid, mi, cr-1);

  if (cr == mj) t->r = NULL;
  else t->r = create(pre, cr+1+pj-mj, pj, mid, cr+1, mj);

  return t;
}

int height(node *t) {
  if (!t) return 0;
  return height(t->l) > height(t->r) ? height(t->l) + 1 : height(t->r) + 1;
}

int main() {
  int n;
  std::cin >> n;
  std::string pre, mid;
  std::cin >> pre >> mid;
  node *root = create(pre, 0, n-1, mid, 0, n-1);
  std::cout << height(root);
  return 0;
}