#include <iostream>
#include <string>
#include <queue>

class node {
  public:
    char d;
    node *lch, *rch;
    node(char dt){
      d = dt;
      lch = NULL;
      rch = NULL;
    } 
};

class tree {
  public:
    node *root;
    int pos;
    std::string dic;
    tree(std::string str) {
      pos = 0;
      dic = str;
      root = create();
    }
    node* create() {
      char ch = dic[pos++];
      if (ch=='#') return NULL;
      else {
        node *t = new node(ch);
        t->rch = create();
        t->lch = create();
        return t;
      }
    }
    void pre(node *t) {
      if (t) {
        std::cout << t->d << ' ';
        pre(t->lch);
        pre(t->rch);
      }
    }
  
    void mid(node *t) {
      if (t) {
        mid(t->lch);
        std::cout << t->d << ' ';
        mid(t->rch);
      }
    }

    void post(node *t) {
      if (t) {
        post(t->lch);
        post(t->rch);
        std::cout << t->d << ' ';
      }
    }

    void lv(node *t) {
      std::queue<node*> q;
      q.push(t);
      while (!q.empty()) {
        t = q.front();
        q.pop();
        std::cout << t->d << ' ';
        if (t->lch) q.push(t->lch);
        if (t->rch) q.push(t->rch);
      }
    }
};


int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string str;
    std::cin >> str;
    tree tr(str);
    if (tr.root) {
      tr.pre(tr.root);
      std::cout << '\n';
      tr.mid(tr.root);
      std::cout << '\n';
      tr.post(tr.root);
      std::cout << '\n';
      tr.lv(tr.root);
      std::cout << '\n';
    } else {
      std::cout << "NULL\nNULL\nNULL\nNULL\n";
    }
  }
}