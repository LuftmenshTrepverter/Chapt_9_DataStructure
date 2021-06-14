#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> q;

int main()
{
    int n;
    long long temp, x, y, ans = 0;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%lld", &temp); //接收得用lld
        q.push(temp);
    }
    while (q.size()>1)
    {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);
    }
    printf("%lld\n", ans); //输出得用lld
    return 0;
}

