#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int color[1005];
vector<int> adjacent[1005];


int DFS(int i)
{
	color[i] = 1;
	for(auto x : adjacent[i])
	{
		if(color[x] == 0)
		{
			if(DFS(x)) return 1;
		}
		else if(color[x] == 1)
		{
			return 1;
		}
	}
	color[i] = 2;
	return 0;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;
		for(int i = 1; i <= m; i++)
		{
			int x, y; cin >> x >> y;
			adjacent[x].push_back(y);
		}
		int check = 0;
		for(int i = 1; i <= n; i++)
		{
			if(color[i] == 0)
			{
				if(DFS(i))
				{
					check = 1;
					cout << "YES" << endl;
					break;
				}
			}
		}
		if(!check) cout << "NO" << endl;
		memset(adjacent, 0 , sizeof(adjacent));
		memset(color, 0 , sizeof(color));
	}
}