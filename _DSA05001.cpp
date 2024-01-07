#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
int dp[1005][1005];

int main()
{
	int t; 
	cin >> t;
	while(t--)
	{
		string s, t; cin >> s >> t;
		s = "0" + s;
		t = "1" + t;
		int n = s.size();
		int m = t.size();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(i==0||j==0) dp[i][j] = 0;
				else if(s[i]==t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);	
				} 
			}
		}
		cout << dp[n - 1][m - 1] << endl;
	}
}