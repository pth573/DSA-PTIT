#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> v;
int r[101][101];
int l[101][101];
int up[101][101];
int down[101][101];
int visited[101][101];
int n, m, k; 




void DFS(int i, int j)
{
	visited[i][j] = 1;
	if(j + 1 <= n && !visited[i][j + 1] && !r[i][j] && !l[i][j + 1])
	{
		DFS(i, j + 1);
	}
	if(j - 1 >= 1 && !visited[i][j - 1] && !l[i][j] && !r[i][j - 1])
	{
		DFS(i, j - 1);
	}
	if(i + 1 <= n && !visited[i + 1][j] && !down[i][j] && !up[i + 1][j])
	{
		DFS(i + 1, j);
	}
	if(i - 1 >= 1 && !visited[i - 1][j] && !up[i][j] && !down[i - 1][j])
	{
		DFS(i - 1, j);
	}	
}

int main() 
{
	cin >> n >> m >> k;
//	memset(visited, 0 ,sizeof(visited));
//	memset(r, 0, sizeof(r));
//	memset(l, 0, sizeof(l));
//	memset(down, 0, sizeof(down));
//	memset(up, 0, sizeof(up));
	for(int i = 1; i <= m; i++)
	{
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		if(u == x)
		{
			if(v < y)
			{
				r[u][v] = 1;
				l[x][y] = 1;
			}
			else
			{
				l[u][v] = 1;
				r[x][y] = 1;
			}
		}
		else if(v == y)
		{
			if(u > x)
			{
				up[u][v] = 1;
				down[x][y] = 1;
			}
			else
			{
				up[x][y] = 1;
				down[u][v] = 1;
			}
		}
		
	}
	for(int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	ll ans = 0;
	for(int i = 0; i < v.size(); i++)
	{
		DFS(v[i].first, v[i].second);
		int cnt = 0;
		for(int j = i + 1; j < v.size(); j++)
		{
			if(!visited[v[j].first][v[j].second])
			{
				cnt++;
			//	cout << v[i].first << " " << v[i].second << " " << v[j].first << " " << v[j].second << endl;
			}
		}
		ans += cnt;
		memset(visited, 0, sizeof(visited));
	}
	cout << ans << endl;
}