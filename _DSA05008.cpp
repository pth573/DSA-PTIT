#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int dp[1000005];

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int s; cin >> s;
		int a[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
//			dp[a[i]] = 1;
		}
		dp[0] = 1;
		for(int i = 0; i < n; i++)
		{
			for(int j = s; j >= 0; j--)
			{
				if(dp[j - a[i]]==1)
				{
					dp[j] = 1;
				}
			}
		}
//		for(int i = 0; i <= s; i++) cout << dp[i] << " ";
//		cout << endl;
		if(dp[s]) cout <<  "YES" << endl;
		else cout << "NO" << endl;
//		cout << dp[s] << endl;
		memset(dp, 0, sizeof(dp));
	}
}
