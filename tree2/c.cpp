#include <iostream>
#include <queue>

int cnt;
int x[101] = {-1};
char y[101] = {'0'};
char prt[101] = {'0'};

typedef struct node {
  char name, fa;
  node *lch, *rch;
}*tree;

tree init() {
  tree t;
  t = new node;
  t->lch = NULL;
  t->rch = NULL;
  return t;
}

void create(tree& t, char name) {
  char c;
  std::cin >> c;
  if (c == '#') t = NULL;
  else {
    t = new node;
    t->name = c;
    t->fa = name;
    create(t->lch, t->name);
    create(t->rch, t->name);
  }

}

void level(tree& t) {
  std::queue<tree> q;
  tree s = t;
  if (s) q.push(s);
  int i = 0, j = 0;
  while (!q.empty()) {
    s = q.front();
    q.pop();
    if (s) {
      cnt++;
      y[i++] = s->name;
      prt[j++] = s->fa;
      if(s->lch) q.push(s->lch);
      if(s->rch) q.push(s->rch);
    }
  }
}

void gx() {
  x[0] = -1;
  for (int i = 1;i < cnt; i++) {
    for (int j = 0; j < cnt; j++) {
      if (prt[i] == y[j])x[i] = j;
    }
  }
}

int main() {
  int t;
  std::cin >> t;
  while(t--) {
    cnt = 0;
    tree tr;
    create(tr, '-1');
    level(tr);
    gx();
    for (int i = 0; i < cnt; i++) {
      std::cout << y[i] << " \n"[i==cnt-1];
    }
    for (int i = 0; i < cnt; i++) {
      std::cout << x[i] << " \n"[i==cnt-1];
    }
  }
}