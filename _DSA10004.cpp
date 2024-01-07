#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

vector<int> adjacent[1005];
int visited[1005];
int degree[1005];

void DFS(int i)
{
	visited[i] = 1;
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
	int t; cin >> t;
	while(t--)
	{
		int euler_circle = 2;
		int euler_road = 1;
		int n, m; cin >> n >> m;
		for(int i = 1; i <= m; i++)
		{
			int x, y; cin >> x >> y;
			adjacent[x].push_back(y);
			adjacent[y].push_back(x);
			degree[x]++; degree[y]++;
		}
		int cnt = 0; // dem so bac le
		for(int i = 1; i <= n; i++)
		{
			if(degree[i] % 2 != 0)
			{
				euler_circle = 0; // bac le => ko co chu trinh
				cnt++;
			}
		}
		if(cnt != 0 && cnt != 2) euler_road = 0;
		
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!visited[i] && degree[i] != 0)
			{
				DFS(i);
				sum++;
			}
		}
		if(sum != 1)
		{
			euler_circle = 0;
			euler_road = 0;
		}
		if(euler_circle)
		{
			cout << euler_circle << endl;
		}
		else if(euler_road)
		{
			cout << euler_road << endl;
		}
		else cout << "0" << endl;
		memset(adjacent, 0, sizeof(adjacent));
		memset(visited, 0, sizeof(visited));
		memset(degree, 0, sizeof(degree));
	}
}