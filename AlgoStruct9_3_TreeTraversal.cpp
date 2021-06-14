#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 50;

struct node
{
    int data;
    int layer;
    vector<int> child;
}Node[maxn];

int index = 0;
int newNode(int v)
{
    Node[index].data = v;
    Node[index].child.clear(); //清空子节点
    return index++;
}

void PreOrder(int root)
{
    printf("%d ", Node[root].data);

    for (int i = 0; i < Node[root].child.size(); i++)
    {
        PreOrder(Node[root].child[i]);
    }
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
        for (int i = 0; i < Node[now].child.size(); i++)
        {
            int nowChild = Node[now].child[i];
            Node[nowChild].layer = Node[now].layer + 1;
            q.push(nowChild);
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
}


