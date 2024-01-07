#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adjacent[1005];
int visited[1005];
int parent[1005];
vector<int> ans;

int DFS(int i)
{
	visited[i] = 1;
	for(auto x : adjacent[i])
	{
		if(!visited[x])
		{
			ans.push_back(x);
			parent[x] = i;
			if(DFS(x)) return 1;
			ans.erase(ans.end() - 1, ans.end()); 	
		}
		else
		{
			if(x != parent[i] && x == 1)
			{
				ans.push_back(x);
				return 1;
			}
		}
	}
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
			adjacent[y].push_back(x);
		}
		for(int i= 1; i <= n; i++)
		{
			sort(adjacent[i].begin(), adjacent[i].end());
		}
		ans.push_back(1);
		if(DFS(1))
		{
			for(auto x : ans) cout << x << " ";
			cout << endl;
		}
		else cout << "NO" << endl;
		ans.clear();
		memset(adjacent, 0, sizeof(adjacent));
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
	}
}

