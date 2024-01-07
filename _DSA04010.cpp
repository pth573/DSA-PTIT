#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 123456789;
int dp[1000];

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int sum1 = 0; // luu tong max cap nhat dau
		int sum2 = INT_MIN; // luu tong max sau khi + a[i];
		for(int i = 0; i < n; i++)
		{
			sum1 += a[i];
			if(sum1 > sum2)
			{
				sum2 = sum1;
			}
			if(sum1 < 0) sum1 = 0;
		}
		cout << sum2 << endl;
	}
}


#include <bits/stdc++.h>
using namespace std;


int summax(int l, int m, int r, int a[])
{
	int Sum_left = INT_MIN;
	int sum = 0;
	for(int i = m; i >= l; i--)
	{
		sum+=a[i];
		Sum_left = max(Sum_left, sum);
	}
	
	int Sum_right = INT_MIN;
	sum = 0;
	for(int i = m + 1; i <= r; i++)
	{
		sum+=a[i];
		Sum_right = max(Sum_right, sum);
	}
	return Sum_left + Sum_right;
}


int solve(int l, int r, int a[])
{
	if(l==r) return a[l];
	int m = (l + r) / 2;
	int sumleft = solve(l, m, a);
	int sumright = solve(m + 1, r, a);
	int cross = summax(l, m, r, a);
	return max({cross, sumleft, sumright});
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << solve(0, n - 1, a) << endl;
	}
}