#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adjacent[100005];
int visited[100005];
int n, m;
vector<int> ans;

int DFS(int i, int par)
{
	visited[i] = 1;
	for(auto x : adjacent[par])
	{
		if(find(adjacent[x].begin(), adjacent[x].end(), i) == adjacent[x].end() && i != x) return 0;
	}
	
	for(int x : adjacent[i])
	{
		if(!visited[x])
		{
			if(!DFS(x, i)) return 0;
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
		for(int i = 0; i < m; i++)
		{
			int x, y; cin >> x >> y;
			adjacent[x].push_back(y);
			adjacent[y].push_back(x);
		}	
		int ans = 1;
		for(int i = 1; i <= n; i++)
		{
			if(!visited[i])
			{
				if(!DFS(i , 0))
				{
					ans = 0;
					break;	
				} 
			}
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
		memset(adjacent, 0, sizeof(adjacent));
		memset(visited, 0 , sizeof(visited));
	}
}

