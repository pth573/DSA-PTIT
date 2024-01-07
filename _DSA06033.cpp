#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		ll a[n + 1];
		pair<int, int> v[100005];
		for(int i = 1; i <= n; i++)
		{
			cin >> v[i].first;
			v[i].second = i;
			
		}
		int ans = 0;
		sort(v + 1, v + n + 1, cmp);
		int cnt[100005] = {0};
		int j = n; // bien lon nhat ko ton tai so voi cac so ben trai v[i].second;
		for(int i = 1; i <= n; i++)
		{
			int x = v[i].second;
			cnt[x] = 1;
			while(cnt[j] == 1) j--; // tim so lon nhat
			ans = max(ans, j - x);
		}
		if(ans >= 1) cout << ans << endl;
		else cout << "-1" << endl;
	}
}