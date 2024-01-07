#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> adjacent[1005];
int visited[1005];
int color[1005];

int DFS(int i)
{
	visited[i] = 1;
	for(auto x : adjacent[i])
	{
		if(!visited[x])
		{
			color[x] = 1 - color[i];
			DFS(x);
		}
		else
		{
			if(color[x] == color[i]) return 0; 
		}
	}
	return 1;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= m; i++)
		{
			int x, y; cin >> x >> y;
			adjacent[x].push_back(y);
			adjacent[y].push_back(x);
		}
		int check = 1;
		for(int i = 1; i <= n; i++)
		{
			if(!DFS(i))
			{
				check = 0;
				break;
			}		
		}
		if(check) cout << "YES" << endl;
		else cout << "NO" << endl;
		memset(visited, 0, sizeof(visited));
		memset(adjacent, 0, sizeof(adjacent));
		memset(color, 0, sizeof(color));
 	}
}

