#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

const int mod = 1e9 + 7;

ll dp[101][101];
ll ans[101];
ll sum[101];

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= 100; i++)
	{
		for(int j = 1; j <= 9; j++)
		{
			if(i == 1)
			{
				dp[i][j] = 1;
				ans[i] = 9;
			}
			else
			{
				if(j == 1) dp[i][j] = ans[i - 1];
				else dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
				ans[i] += dp[i][j];
			}
 		}
 		sum[i] = sum[i - 1] + ans[i];
 		sum[i] %= mod;
	}
	while(t--)
	{
		int n; cin >> n;
		cout << sum[n] + 1 << endl;
		memset(dp, 0, sizeof(dp));
	}
}