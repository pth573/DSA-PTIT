#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 123456789;

long long powmod(ll n, ll k)
{
	if(k == 0) return 1;
	ll x = powmod(n, k / 2);
	if(k%2==1) return (((x%mod) * (x%mod))%mod * n%mod)%mod;
	else return ((x%mod) * (x%mod))%mod;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		cout << powmod(2, n - 1) << endl;
	}
}