#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, v;
int color[1005];
vector<int> adjacent[1005];
int x[1005];

int check(int i)
{
	for(int x : adjacent[i])
	{
		if(color[x] == color[i])
		{
			return 0;
		}
	}
	return 1;
}

int backTracking(int i)
{
	for(int j = 1; j <= v; j++)
	{
		color[i] = j;
		if(check(i))
		{
			if(i == n) return 1;
			if(backTracking(i + 1)) return 1;
		}
		color[i] = 0;
	}
	return 0;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		memset(x, 0, sizeof(x));
		memset(adjacent, 0, sizeof(adjacent));
		memset(color, 0, sizeof(color));
		cin >> n >> m >> v;
		for(int i = 1; i <= m ; i++)
		{
			int x, y; cin >> x >> y;
			adjacent[x].push_back(y);
			adjacent[y].push_back(x);
		}
		if(backTracking(1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

