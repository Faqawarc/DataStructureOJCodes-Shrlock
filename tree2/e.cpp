#include <iostream>
#include <string>

int res;

typedef struct binode {
  char d;
  binode *lch, *rch;
}node, *tree;

tree buildtree(const char *pre, const char *mid, int n) {
  tree tr;
  if (!n)return NULL;
  char c = pre[0];
  int i = 0;
  while (mid[i] != c) i++;
  tr = (tree)malloc(sizeof(node));
  tr->d = c;
  tr->lch = buildtree(pre+1, mid, i);
  tr->rch = buildtree(pre+i+1, mid+i+1, n-i-1);
  return tr;
}

void getlv(tree t, int lv) {
  if (t) {
    lv++;
    getlv(t->lch, lv);
    getlv(t->rch, lv);
  } else return;
  res = std::max(res, lv);
}

int main() {
  int n;
  tree tr = NULL;
  std::cin >> n;
  std::string str;
  const char *pre, *mid;
  std::cin >> str;
  pre = str.data();
  std::cin >> str;
  mid = str.data();
  tr = buildtree(pre, mid, n);
  getlv(tr, res);
  std::cout << res;
  return 0;
}