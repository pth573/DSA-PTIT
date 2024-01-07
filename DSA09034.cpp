#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int visited[101][101];
int n, m;
pair<int, int> p[8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
char a[101][101];

void DFS(int i, int j)
{
	visited[i][j] = 1;
	for(int k = 0; k < 8; k++)
	{
		int in = i + p[k].first;
		int jn = j + p[k].second;
		if(in >= 0 && in <= n && jn >= 1 && jn <= m && a[in][jn] == 'W' && !visited[in][jn])
		{
			DFS(in, jn);
		}
	}
}

int main() 
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == 'W' && !visited[i][j])
			{
				cnt++;
				DFS(i, j);
			} 
		}
	}
	cout << cnt << endl;
}