#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int x)
{
    node* Node = new node;
    Node->data = x;
    Node->lchild = NULL;
    Node->rchild = NULL;
    return Node;
}

//查找
void Search(node* root, int x)
{
    if (root == NULL)
    {
        printf("fail");
        return;
    }

    if (root->data == x)
    {
        printf("%d\n", root->data);
    }
    
    else if (root->data < x)
    {
        Search(root->lchild, x);
    }
    else
    {
        Search(root->rchild, x);
    }
}

void InsertBTS(node*& root, int x)
{
    if (root == NULL)
    {
        root = newNode(x);
        return;
    }
    
    if (x < root->data)
    {
        InsertBTS(root->lchild, x);
    }
    else
    {
        InsertBTS(root->rchild, x);
    }
}

void preOrder(node* root, vector<int>& vi)
{
    if (root == NULL)
    {
        return;
    }
    vi.push_back(root->data);
    preOrder(root->lchild, vi);
    preOrder(root->rchild, vi);
}

void preOrderMirror(node* root, vector<int>& vi)
{
    if (root == NULL)
    {
        return;
    }
    vi.push_back(root->data);
    preOrderMirror(root->rchild, vi);
    preOrderMirror(root->lchild, vi);
}

void postOrder(node* root, vector<int>& vi)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->lchild, vi);
    postOrder(root->rchild, vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root, vector<int>& vi)
{
    if (root == NULL)
    {
        return;
    }

    postOrderMirror(root->rchild, vi);
    postOrderMirror(root->lchild, vi);
    vi.push_back(root->data);
}



node* Create(int data[], int n)
{
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        InsertBTS(root, data[i]);
    }
    return root;
}


//寻找以root为根结点的树中的最大权值结点
node* findMAX(node* root)
{
    while (root->rchild != NULL)
    {
        root = root->rchild;
    }

    return root;
}

//寻找以root为根结点的树中的最小权值结点
node* findMIN(node* root)
{
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }

    return root;
}

void delNode(node*& root, int x)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == x)
    {
        if (root->lchild == NULL && root->rchild == NULL)
        {
            root = NULL;
        }
        else if (root->lchild != NULL)
        {
            node* pre = findMAX(root->lchild);
            root->data = pre->data;
            delNode(root->lchild, root->data);
        }
        else
        {
            node* next = findMIN(root->rchild);
            root->data = next->data;
            delNode(root->rchild, root->data);
        }
    }

    else if (root->data > x)
    {
        delNode(root->lchild, x);
    }

    else 
    {
        delNode(root->rchild, x);
    }
}

vector<int> origin, pre, preM, post, postM;
int main()
{
    int n, data[20];
    node* root = NULL;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &data[i]);
        origin.push_back(data[i]);
    }
    root = Create(data, n);
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    
    if (origin == pre)
    {
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            printf("%d", post[i]);
            if (i < post.size()-1)
            {
                printf(" ");
            }
        }
    }
    else if (origin == preM)
    {
        printf("YES\n");
        for (int i = 0; i < postM.size(); i++)
        {
            printf("%d", postM[i]);
            if (i < postM.size() - 1)
            {
                printf(" ");
            }
        }
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}

