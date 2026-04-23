#include <bits/stdc++.h>

class node{
  public:
    int data;
    node *next;
};


class list{
  public:
    node *head;
    int size;
};

list* linit() {
  list *L = new list;
  L->size = 0;
  L->head = new node;
  L->head->data = NULL;
  L->head->next = NULL;
  return L;
}

void linsert(list *L, int pos, int data) {


  if (L == NULL) pos = 0;

  node *nnode = new node;
  nnode->data = data;
  nnode->next = NULL;

  node *pnode = L->head;

}

int main() {

  return 0;
}