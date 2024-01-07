#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

int dp[100005];

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		// ko dc xet tai 0
		for(int i = 1; i <= n; i++) dp[i] = 1e9;
		int ans = INT_MAX;
		for(int i = 1; i <= sqrt(n); i++) // co the doi cho 2 vong lap
		{
			for(int j = 1; j <= n; j++)
			{
				if(j >= i * i)
				{
					 dp[j] = min(dp[j], dp[j - i * i] + 1);
				}
			}
		}
		cout << dp[n] << endl;
		memset(dp, 0, sizeof(dp));
	}
}