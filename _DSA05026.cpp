#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int w[1000001];
int dp[1000001] ;

void init(int n, int kg)
{
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = kg; j >= w[i]; j--) // j >= 1 rte ??
		{
			if(j >= w[i])
			{
				if(dp[j - w[i]])
				{
					dp[j] = 1;
				}
			}
		}
	}
	int ans = INT_MIN;
	for(int i = kg; i >= 0; i--)
	{
		if(dp[i])
		{
			ans = max(ans, i);
			break;
		}
	}
	cout << ans << endl;
}

int main() {
	int kg, n; cin >> kg >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	init(n, kg);
}