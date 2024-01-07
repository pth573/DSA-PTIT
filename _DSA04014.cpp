#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;


ll solve(int l, int m, int r, ll a[])
{
	vector<ll> v1;
	vector<ll> v2;
	ll ans = 0;
	for(int i = l ; i <= m; i++)
	{
		v1.push_back(a[i]);
	}
	for(int i = m + 1 ; i <= r; i++)
	{
		v2.push_back(a[i]);
	}
	int i = 0; int j = 0;
	while(i < v1.size() && j < v2.size())
	{
		if(v1[i] <= v2[j])
		{
			a[l] = v1[i];
			l++;
			i++;
		}
		else
		{
			ans += v1.size() - i;
			a[l] = v2[j];
			l++;
			j++;
		}
	}
	while(i < v1.size())
	{
			a[l] = v1[i];
			i++;
			l++;	
	}
	while(j < v2.size())
	{
			a[l] = v2[j];
			j++;
			l++;		
	}
	return ans;
}


ll merge(int l, int r, ll a[])
{
	if(l >= r) return 0;
	int m = (l + r) / 2;
	ll sum = 0;
	sum += merge(l, m, a);
	sum += merge(m + 1, r, a);
	sum += solve(l, m, r, a);
	return sum; 
}


int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		ll a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << merge(0, n - 1, a) << endl;
	}
}