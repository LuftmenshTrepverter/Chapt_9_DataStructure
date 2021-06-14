#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 110;
int father[maxn];
bool isRoot[maxn];

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		isRoot[i] = false;
	}
}

int findFather(int x)
{
	while (x != father[x])
	{
		x = father[x];
	}
	return x;
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
	{
		father[faB] = faA;
	}
}

int zipFindFather(int x)
{
	int a = x;
	while (x != father[x])
	{
		x = father[x];
	}

	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}

	return x;
}

int main()
{
	int n, m, a, b;
	scanf_s("%d%d", &n, &m);
	init(n);

	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &a, &b);
		Union(a, b);
	}

	for (int i = 1; i <= n; i++)
	{
		isRoot[findFather(i)] = true;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += isRoot[i];
	}

	printf("%d\n", ans);
	return 0;
}


