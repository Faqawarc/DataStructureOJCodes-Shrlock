#include <iostream>
#include <string>

class node {
  public:
    char data;
    node *left;
    node *right;
    node(): left(NULL), right(NULL){};
    ~node(){};
};

class tree {
  private:
    node *root;
    int pos;
    std::string str;
    node *makeTree();
    void order(node *t);
  public:
    tree(){};
    ~tree(){};
    int leaf;
    void create(std::string arr);
    void order();
};

void tree::create(std::string arr) {
  pos = 0;
  leaf = 0;
  str.assign(arr);
  root = makeTree();
}

node* tree::makeTree() {
  node *T;
  char ch;
  ch = str[pos++];
  if (ch == '0') T = NULL;
  else {
    T = new node();
    T->data = ch;
    T->left = makeTree();
    T->right = makeTree();
  }
  return T;
}

void tree::order() {
  if (root == NULL) leaf++;
  else order(root);
}

void tree::order(node* t) {
  if (t) {
    if (t->left==NULL && t->right==NULL) leaf++;
    else {
      order(t->left);
      order(t->right);
    }
  }
}

void solve() {
  std::string s;
  std::cin >> s;
  tree tr;
  tr.create(s);
  tr.order();
  std::cout << tr.leaf << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}