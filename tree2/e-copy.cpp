#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int res;

typedef struct bitnode {
    struct bitnode *lchild;
    struct bitnode *rchild;
    char data;
} BiTNode,*BiTree;

void build(string xianxu,int i,int j,string zhongxu,int k,int h,BiTree *t) {
    int m;

    *t =(BiTree)malloc(sizeof(BiTNode));

    (*t)->data=xianxu[i];
    m=k;
    while(zhongxu[m]!=xianxu[i])
        m++;

    if(m==k)
        (*t)->lchild=NULL;
    else
        build(xianxu,i+1,m-k+i,zhongxu,k,m-1,&(*t)->lchild);

    if(m==h)
        (*t)->rchild=NULL;
    else
        build(xianxu,m+j-h+1,j,zhongxu,m+1,h,&((*t)->rchild));

}

BiTree ReBiTree(string houxu,string zhongxu,int n) {
    BiTree root;
    if(n<=0)
        root=NULL;
    else
        build(houxu,0,n-1,zhongxu,0,n-1,&root);
    return root;

}

void preorder(BiTree bt, int lv){
    if(bt ==NULL) return;
    else {
      lv++;
        preorder(bt->lchild, lv);
        preorder((bt->rchild), lv);
    }
    res = max(lv, res);
}


int main() {
    BiTree T;
    int n;
    string  xianxu="";
    string zhongxu="";
    T = NULL;
    cin>>n;
    cin>>xianxu;
    cin>>zhongxu;
    T=ReBiTree(xianxu,zhongxu,n);
    preorder(T, 0);
    std::cout << res;
    return 0;
}

