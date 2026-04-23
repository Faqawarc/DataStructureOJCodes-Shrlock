#include <iostream>
#include <string>

class node {
  public:
    char data;
    node* left;
    node* right;
    node(): left(NULL), right(NULL){};
    ~node(){};
};

class tree {
  private:
    node* root;
    int pos;
    std::string str;
    node* make();
    void order(node *t);
    void orderr(node *t);
  public:
    tree(){};
    ~tree(){};
    void create(std::string arr);
    void order();
    void orderr();
};

void tree::create(std::string arr) {
  pos = 0;
  str.assign(arr);
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
    t->left = make();
    t->right = make();
  }
  return t;
}

void tree::order() {
  order(root);
}

void tree::orderr() {
  orderr(root);
}

void tree::order(node* t) {
  if (t) {
    if (t->left == NULL && t->right == NULL)
      std::cout << t->data << ' ';
    else {
      order(t->left);
      order(t->right);
    }
  }
}

void tree::orderr(node *t) {
  if (t) {
    if (t->left) {
      if (!t->left->left && !t->left->right) std::cout << t->data << ' ';
    }
    orderr(t->left);
    if (t->right) {
      if(!t->right->left && !t->right->right) std::cout << t->data << ' ';
    }
    orderr(t->right);
  }
}

void solve() {
  std::string s;
  std::cin >> s;
  tree tr;
  tr.create(s);
  tr.order();
  std::cout << '\n';
  tr.orderr();
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}