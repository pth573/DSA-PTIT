#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans;

void recursion(int n, int step)
{
    if(step > ans) return;
	if(n == 1)
	{
		ans = min(ans, step);
		return;
	}
	if(n % 2 == 0)
	{
		recursion(n / 2, step + 1);
	}
	if(n % 3 == 0)
	{
		recursion(n / 3, step + 1);
	}
	if(n >= 1)
	{
		recursion(n - 1, step + 1);
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		ans = INT_MAX;
		recursion(n, 0);
		cout << ans << endl;
	}
}