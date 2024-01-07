#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;

void init(ll n)
{
	ll x = 1ll * log2(n);
	for(ll i = 0; i <= x; i++)
	{
		v.push_back(1ll * pow(2, i));
	}
}

ll Solution(ll n, ll pos, ll ind)
{
	if(pos == v[ind]) return n % 2;
	else if(pos < v[ind]) return Solution(n / 2, pos, ind - 1);
	else return Solution(n / 2, pos - v[ind], ind - 1); 
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		ll n, l, r;
		cin >> n >> l >> r;
		ll ans = 0;
		init(n);
		ll ind = v.size() - 1;
		for(ll i = l ; i <= r; i++)
		{
			ans += Solution(n, i, ind);
		}
		cout << ans << endl;
	}
}