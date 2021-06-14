#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data, height;
    node* lchild;
    node* rchild;
};

node* newNode(int v)
{
    node* Node = new node;
    Node->data = v;
    Node->height = 1;
    Node->lchild = NULL;
    Node->rchild = NULL;

    return Node;
}

int getHeight(node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->height;
}

//一个结点的平衡因子等于该结点左右子树高度之差
int getBalFactor(node* root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updataHeight(node* root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void Search(node* root, int x)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == x)
    {
        printf("%d\n", root->data);
    }
    else if (x < root->data)
    {
        Search(root->lchild, x);
    }
    else
    {
        Search(root->rchild, x);
    }
}

void LeftRotation(node* &root)
{
    node* temp = root->lchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updataHeight(temp);
    updataHeight(root);
    root = temp;
}

void RightRotation(node* root)
{
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updataHeight(root);
    updataHeight(temp);
    root = temp;
}

void Insert(node*& root, int x)
{
    if (root == NULL)
    {
        root = newNode(x);
    }
    if (x < root->data)
    {
        Insert(root->lchild, x);
        updataHeight(root);
        if (getBalFactor(root) == 2)
        {
            if (getBalFactor(root->lchild) == 1)
            {
                RightRotation(root);
            }
            else if (getBalFactor(root->lchild) == -1)
            {
                LeftRotation(root->lchild);
                RightRotation(root);
            }
        }
    }
    else
    {
        Insert(root->rchild, x);
        updataHeight(root);
        if (getBalFactor(root) == -2)
        {
            if (getBalFactor(root->rchild) == -1)
            {
                LeftRotation(root);
            }
            else if (getBalFactor(root->rchild) == 1)
            {
                RightRotation(root->rchild);
                LeftRotation(root);
            }
        }
    }
}

node* Create(int data[], int n)
{
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        Insert(root, data[i]);
    }

    return root;
}

int main()
{
    std::cout << "Hello World!\n";
}


