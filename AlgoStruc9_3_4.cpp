#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 110;

struct node
{
    int weight;
    vector<int> child;

}Node[MAXN];

bool cmp(int a, int b)
{
    return Node[a].weight > Node[b].weight;
}

int n, m, S; //结点数，边数，给定的和

int path[MAXN]; //递归过程中产生的路径上的结点编号

void DFS(int index, int numNode, int sum)
{
    if (sum > S)
    {
        return;
    }

    //到当前访问结点index为止，输入中需要达到的S已经得到
    if (sum == S)
    {

        //如果到这个时候还不是叶子结点就直接返回
        if (Node[index].child.size() != 0)
        {
            return; //还没达到叶子结点，直接返回
        }

        //当前结点是叶子结点
        for (int i = 0; i < numNode; i++)
        {
            //输出path数组中所有的数据
            printf("%d（%d） ", Node[path[i]].weight, path[i]);
            if (i < numNode - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
        return;
    }

    //sum<s ,枚举当前结点index的所有子结点
    //接着向下一层递归
    for (int i = 0; i < Node[index].child.size(); i++)
    {
        int child = Node[index].child[i];
        //对每一个子结点，先把他存到数组中去
        path[numNode] = child;
        DFS(child, numNode + 1, sum + Node[child].weight);

    }
}


int main()
{
    scanf_s("%d%d%d", &n, &m, &S);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &Node[i].weight);
    }
    int id, k, child;
    for (int i = 0; i < m; i++)
    {
        scanf_s("%d%d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            scanf_s("%d", &child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);

    }
    path[0] = 0;
    DFS(0, 1, Node[0].weight);

    return 0;
}

