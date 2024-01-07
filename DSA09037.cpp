#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> adjacent[1005];
vector<int> v;
int visited[1005];
int cnt[1005];
int k, n, m;
int ans = 0;

void DFS(int i)
{
	visited[i] = 1;
	cnt[i]++;
	if(cnt[i] == k) ans++;
	for(auto x : adjacent[i])
	{
		if(!visited[x])
		{
			DFS(x);
		}
	}
}


int main() 
{
	cin >> k >> n >> m;
	for(int i = 1; i <= k; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adjacent[x].push_back(y);
//		adjacent[y].push_back(x);
	}
	for(auto x : v)
	{
		DFS(x);
		memset(visited, 0, sizeof(visited));
	}
//	for(int i = 1; i <= n; i++)
//	{
//		if(visited[i] == n)
//		{
//			ans++;
//		}
//	}
	cout << ans << endl;
}