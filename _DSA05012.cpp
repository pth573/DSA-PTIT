#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
ll dp[1005][1005];

void init(int n, int k)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			if(k==0) dp[i][j] = 1;
			else if(i == j) dp[i][j] = 1;
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				dp[i][j] %= mod;
			}
		}
	}
}

int main() {
	int t; cin >> t;
	init(1001, 1001);
	while(t--)
	{
		int n, k; cin >> n >> k;
		cout << dp[n][k] << endl;
//		memset(dp, 0, sizeof(dp));
	}
}
