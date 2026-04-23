#include <iostream>
#include <string>
#include <queue>
using namespace std;

class node {
  public:
    char data;
    node* l;
    node* r;
    node(): l(NULL), r(NULL){};
    ~node(){};
};

class tree {
  private:
    node* root;
    int pos;
    string str;
    node* make();
  public:
    tree(){};
    ~tree(){};
    void create(string a);
    void order();
    void order(node* t);
};

void tree::create(string a) {
  pos = 0;
  str.assign(a);
  root = make();
}

node* tree::make() {
  node *t;
  char c;
  c = str[pos++];
  if (c=='0') t = NULL;
  else {
    t = new node;
    t->data = c;
    t->l = make();
    t->r = make();
  }
  return t;
}

void tree::order() {
  order(root);
}

void tree::order(node *t) {
  queue<node *> q;
  q.push(t);
  while (!q.empty()) {
    t = q.front();
    q.pop();
    cout << t->data;
    if (t->l)
      q.push(t->l);
    if (t->r)
      q.push(t->r);
  }
}

void solve() {
  string s;
  cin >> s;
  tree tr;
  tr.create(s);
  tr.order();
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}