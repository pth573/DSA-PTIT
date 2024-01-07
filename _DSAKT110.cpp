#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[10000005];
int a[10000005];
int n;

void solve()
{
	dp[1] = a[1];
	dp[2] = max(a[1], a[2]);
	for(int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	}
	cout << dp[n] << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		solve();
		memset(dp, 0, sizeof(dp));
	}
}