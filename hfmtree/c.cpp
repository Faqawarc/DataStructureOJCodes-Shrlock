#include <iostream>
#include <string>

class node {
  public:
    char d;
    int w, h;
    node *lch, *rch;
    node(int ht, char dt){
      d = dt;
      h = ht;
      w = 0;
      lch = NULL;
      rch = NULL;
    } 
};

class tree {
  public:
    node *root;
    int pos, ix;
    std::string dic;
    int sum;
    tree(int *w, std::string str) {
      pos = ix = 0;
      sum = 0;
      dic = str;
      root = create(w, 0);
    }
    node* create(int *w, int fht) {
      char ch = dic[pos++];
      if (ch=='0') return NULL;
      else {
        node *t = new node(fht+1, ch);
        if (ch>='A' && ch<='Z') t->w=w[ix++];
        t->lch = create(w, t->h);
        t->rch = create(w, t->h);
        return t;
      }
    }
    void pre(node *t) {
      if (t) {
        sum += t->w * (t->h - 1);
        pre(t->lch);
        pre(t->rch);
      }
    }
};

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string str;
    int n;
    std::cin >> str >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    tree tr(a, str);
    tr.pre(tr.root);
    std::cout << tr.sum << '\n';
  }
  return 0;

}