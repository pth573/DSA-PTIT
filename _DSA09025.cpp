#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
vector<int> adjacent[1005];
int visited[1005];
int parent[1005];

void DFS(int i)
{
	visited[i] = 1;
	for(auto x : adjacent[i])
	{
		if(!visited[x])
		{
			parent[x] = i;
			DFS(x);
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;
		int s, t; cin >> s >> t;
		for(int i = 1; i <= m; i++)
		{
			int x, y; 
			cin >> x >> y;
			adjacent[x].push_back(y);
		}
		DFS(s);
		int cnt = 0; 
		if(!visited[t])
		{
			cout << "-1" << endl;
		}
		else
		{
			vector<int> tmp; // dung string bi sai
			tmp.push_back(t);
			while(s!=t)
			{
				tmp.push_back(parent[t]);
	//			cout << parent[t] << " ";
				t = parent[t];
			}
			reverse(tmp.begin(), tmp.end());
//			cout << cnt << endl;
			for(int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
			cout << endl;
		}
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		memset(adjacent, 0, sizeof(adjacent));
	}
}