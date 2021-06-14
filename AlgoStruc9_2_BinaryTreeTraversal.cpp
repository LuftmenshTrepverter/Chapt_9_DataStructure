#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 50;

struct node
{
    int data;
    int lchild;
    int rchild;
}Node[maxn];

int index = 0; 
int newNode(int v)
{
    Node[index].data = v; //分配一个Node数组中的结点给新的结点，index为其坐标
    Node[index].lchild = -1; //以-1 或者 maxn表示空
    Node[index].rchild = -1;
    return index++;
}

//查找修改
void Search(int root, int x, int newdata)
{
    //root为根结点在数组中的坐标
    if (root == -1)
    {
        return; 
    }

    if (Node[root].data == x)
    {
        Node[root].data = newdata;
    }

    Search(Node[root].lchild, x, newdata);
    Search(Node[root].rchild, x, newdata);

}

//插入
void Inseart(int& root, int x)
{
    if (root == -1)
    {
        root = newNode(x);
    }

    if (true)
    {
        Inseart(Node[root].lchild, x); //根据题目往左子树搜索
    }
    else
    {
        Inseart(Node[root].rchild, x);
    }

}

//二叉树的建立
int Create(int data[], int n)
{
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        Inseart(root, data[i]);
    }

    return root;
}

void PreOrder(int root)
{
    if (root == -1)
    {
        return;
    }

    printf("%d ", Node[root].data);

    PreOrder(Node[root].lchild);

    PreOrder(Node[root].rchild);
}

void InOrder(int root)
{
    if (root == -1)
    {
        return;
    }

    InOrder(Node[root].lchild);

    printf("%d ", Node[root].data);

    InOrder(Node[root].rchild);
}

void PostOrder(int root)
{
    if (root == -1)
    {
        return;
    }

    PostOrder(Node[root].lchild);

    PostOrder(Node[root].rchild);

    printf("%d ", Node[root].data);
}

void LayerOrder(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        printf("%d ", Node[now].data);
        if (Node[now].lchild != -1)
        {
            q.push(Node[now].lchild);
        }
        if (Node[now].rchild != -1)
        {
            q.push(Node[now].rchild);
        }
    }

}

int main()
{
    std::cout << "Hello World!\n";
}


