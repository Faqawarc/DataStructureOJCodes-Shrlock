#include <iostream>
#include <string>

class node {
  public:
    char d;
    int w;
    node *lch, *rch;
    node(char dt){
      d = dt;
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
    int maxx;
    tree(int *w, std::string str) {
      pos = ix = 0;
      maxx = 0;
      dic = str;
      root = create(w);
    }
    node* create(int *w) {
      char ch = dic[pos++];
      if (ch=='0') return NULL;
      else {
        node *t = new node(ch);
        t->w = w[ix++];
        t->lch = create(w);
        t->rch = create(w);
        return t;
      }
    }
    void pre(node *t, int sum) {
      if (t) {
        sum += t->w;
        pre(t->lch, sum);
        pre(t->rch, sum);
      }
      maxx = std::max(maxx, sum);
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
    tr.pre(tr.root, 0);
    std::cout << tr.maxx << '\n';
  }
  return 0;

}