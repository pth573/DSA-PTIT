#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

struct matrix{
	ll a[2][2];
	friend matrix operator * (matrix x, matrix y)
	{
		matrix z;
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				z.a[i][j] = 0;
				for(int k = 0; k < 2; k++)
				{
					z.a[i][j] += x.a[i][k] * y.a[k][j]; 
					z.a[i][j] %= mod;
				}
			}
		}
		return z;
	}
};


matrix binPow(matrix tmp, int n)
{
	if(n == 1)
	{
		return tmp;
	}
	matrix x = binPow(tmp, n / 2);
	if(n % 2 == 0) return x * x;
	else return x * x * tmp;
}


int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		if(n == 0)
		{
			cout << "0" << endl;
			continue;
		}
		matrix tmp;
		tmp.a[0][0] = 1; tmp.a[0][1] = 1; tmp.a[1][0] = 1; tmp.a[1][1] = 0;
		matrix ans = binPow(tmp, n);
		cout << ans.a[0][1] << endl;
	}
}
