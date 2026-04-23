#include <iostream>
#include <string>

class treeNode {
  public:
  char data;
  treeNode *left;
  treeNode *right;
  treeNode():left(NULL), right(NULL){}
  ~treeNode(){}
};

class tree {
  private:
    treeNode *root;
    int pos;
    std::string strTree;
    treeNode* createTree();
    void PreOrder(treeNode* t);
    void InOrder(treeNode* t);
    void PostOrder(treeNode* t);
  public:
    tree(){};
    ~tree(){};
    void create(std::string treeArr);
    void PreOrder();
    void InOrder();
    void PostOrder();
};

void tree::create(std::string treeArr) {
  pos = 0;
  strTree.assign(treeArr);
  root = createTree();
}

treeNode* tree::createTree() {
  treeNode *T;
  char ch;
  ch = strTree[pos++];
  if (ch=='0')
    T = NULL;
  else {
    T = new treeNode();
    T->data = ch;
    T->left = createTree();
    T->right = createTree();
  }
  return T;
}

void tree::PreOrder() {
  PreOrder(root);
}

void tree::PreOrder(treeNode *t) {
  if (t) {
    std::cout << t->data;
    PreOrder(t->left);
    PreOrder(t->right);
  }
}

void tree::InOrder() {
  InOrder(root);
}

void tree::InOrder(treeNode *t) {
  if (t) {
    InOrder(t->left);
    std::cout << t->data;
    InOrder(t->right);
  }
}

void tree::PostOrder() {
  PostOrder(root);
}

void tree::PostOrder(treeNode *t) {
  if (t) {
    PostOrder(t->left);
    PostOrder(t->right);
    std::cout << t->data;
  }
}

void solve() {
  std::string s;
  std::cin >> s;
  tree tr;
  tr.create(s);
  tr.PreOrder();
  std::cout << '\n';
  tr.InOrder();
  std::cout << '\n';
  tr.PostOrder();
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