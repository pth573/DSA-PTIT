#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int w[1000001];
int v[100005];
int dp[1005][1005];
int n, W;

void solve()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= W; j++)
		{
			if(j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][W] << endl;
}

int main() {
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> W;
		for(int i = 1; i <= n; i++)
		{
			cin >> w[i];
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}
		solve();
		memset(dp, 0, sizeof(dp));
		memset(v, 0, sizeof(v));
		memset(w, 0, sizeof(w));
	}
}



