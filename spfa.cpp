#include <bits/stdc++.h>
#define N 10052
#define M 548621
using namespace std;
int n, m;
int a, b, c, s;
int vis[N], head[N], dis[N], cnt[N];
struct node
{
	int ne, to, w;
} edge[M];
int num;
inline void read(int &x)
{
	x = 0;
	int y = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= y;
}
void add(int s, int t, int v)
{
	edge[++num].ne = head[s];
	edge[num].to = t;
	edge[num].w = v;
	head[s] = num;
}
queue<int> q;
void spfa()
{
	q.push(s);
	fill(dis + 1, dis + 1 + n, 0x7fffffff);
	vis[s] = 1;
	dis[s] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].ne)
		{
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].w)
			{
				dis[v] = dis[u] + edge[i].w;
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	read(n);
	read(m);
	read(s);
	for (int i = 1; i <= m; i++)
	{
		read(a);
		read(b);
		read(c);
		add(a, b, c);
	}
	spfa();
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}
}
