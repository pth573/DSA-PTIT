#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int dp[1005];
// giong bai day tang dai nhat 



#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int dp[1005];
// giong bai day tang dai nhat 
// khac moi co dau bang

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			dp[i] = 1;
		}
		int ans = INT_MIN;
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(a[i] >= a[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
				ans = max(ans, dp[i]);
			}
		}
		cout << n - ans << endl;
		memset(dp, 0, sizeof(dp));
	}
}


int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> v;
		for(int i = 0; i < n; i++)
		{
			auto it = upper_bound(v.begin(), v.end(), a[i]);
			if(it == v.end())
			{
				v.push_back(a[i]);
			}
			else *it = a[i];
		}
		cout << n - v.size() << endl;
	}
}
