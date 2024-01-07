#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 123456789;

int check(ll n, ll k)
{
	long long sz = pow(2,n) - 1;
	long long mid = sz/2 + 1;
	if(n==1) return 1;
	if(k == mid) return n;
	else if(k < mid)
	{
		return check(n - 1, k);
	}
	else return check (n - 1, k - mid);
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		ll n; ll k; cin >> n >> k;
		cout << check(n, k) << endl;
	}
}