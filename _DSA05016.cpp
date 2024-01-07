#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

const int mod = 1e9 + 7;

int dp[100005];

int main()
{
	int t; cin >> t;
	dp[1] = 1;
	int x, y, z; x = y = z = 1;
	for(int i = 2; i <= 10001; i++)
	{
		dp[i] = min({dp[x] * 2, dp[y] * 3, dp[z] * 5});
		if(dp[i] == dp[x] * 2) x++;
		if(dp[i] == dp[y] * 3) y++;
		if(dp[i] == dp[z] * 5) z++; 	
	}
	while(t--)
	{
		int n; cin >> n;
		cout << dp[n] << endl;
//		memset(dp, 0, sizeof(dp));
	}
}