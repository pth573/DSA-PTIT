#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1005][1005];

int main()
{
	int test; cin >> test;
	while(test--)
	{
		string s; cin >> s;
		string t; cin >> t;
		s = "A" + s;
		t = "B" + t;
		int n = s.size();
		int m = t.size();
		for(int i = 1; i < n; i++)
		{
			for(int j = 1; j < m; j++)
			{
				if(s[i] == t[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[n - 1][m - 1] << endl;
		memset(dp, 0, sizeof(dp));
	}
}