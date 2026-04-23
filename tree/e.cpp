#include <iostream>
#include <string>

class node {
  public:
    char data;
    node *l, *r;
    node(): l(NULL), r(NULL){};
    ~node(){};
};

class tree {
  private:
    node* root;
    int pos;
    std::string str;
    node* make();
    void order(node *t, int lv);
  public:
    tree(){};
    ~tree(){};
    int level;
    void create(std::string k);
    void order();
};

void tree::create(std::string k) {
  pos = 0;
  level = 0;
  str.assign(k);
  root=make();
}

node* tree::make() {
  node *t;
  char c;
  c = str[pos++];
  if (c == '0') t = NULL;
  else {
    t = new node;
    t->data = c;
    t->l = make();
    t->r = make();
  }
  return t;
}

void tree::order() {
  order(root, level);
}

void tree::order(node* t, int lv) {
  if (t) {
    lv++;
    order(t->l, lv);
    order(t->r, lv);
  }
  level = std::max(lv, level);
}

void solve() {
  std::string s;
  std::cin >> s;
  tree tr;
  tr.create(s);
  tr.order();
  std::cout << tr.level << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}