#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void egyptianFraction(ll p,ll q)
{
	if(p == 0 || q == 0) return;
	if(q % p == 0)
	{
		cout << "1/" << q/p;
		return;
	}
	ll x = q / p + 1;
	cout << "1/" << x << " + ";
	egyptianFraction(p * x - q, q * x);
}

int main() {
	int t; cin >> t;
	while(t--)
	{
		ll p, q;
	    cin >> p >> q;
	    egyptianFraction(p,q);
	    cout << endl;
	}
}
