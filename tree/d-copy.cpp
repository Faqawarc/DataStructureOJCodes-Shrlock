#include <iostream>
#include <queue>
using namespace std;

class BiTNode
{
public:
    char data;
    BiTNode *lchild, *rchild;
    BiTNode(){}
    ~BiTNode(){}
};

class BiTree
{
public:
    BiTNode *root;
    BiTree(){}
    ~BiTree(){}
    void CreateTree();
    void CreateTree(BiTNode *&p);
    void LevelOrder();
    void LevelOrder(BiTNode *p);
};

void BiTree::CreateTree()
{
    CreateTree(root);
}

void BiTree::CreateTree(BiTNode *&p)
{
    char ch;
    cin>>ch;
    if(ch!='0')
    {
        p = new BiTNode;
        p->data = ch;
        CreateTree(p->lchild);
        CreateTree(p->rchild);
    }
    else
        p = NULL;
}

void BiTree::LevelOrder()
{
    LevelOrder(root);
}

void BiTree::LevelOrder(BiTNode *p)
{
    queue<BiTNode *> tq;
    tq.push(p);
    while(!tq.empty())
    {
        p = tq.front();
        tq.pop();
        cout<<p->data;
        if(p->lchild)
            tq.push(p->lchild);
        if(p->rchild)
            tq.push(p->rchild);
    }
    cout<<endl;
}

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        BiTree myTree;
        myTree.CreateTree();
        myTree.LevelOrder();
    }
}
