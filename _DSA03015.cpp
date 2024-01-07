#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; // luong thuc mua max / ngay
		int s; // so ngay 
		int m; // luong thuc ton tai/ ngay
		cin >> n >> s >> m;
		if(m > n)
		{
			cout << "-1" << endl;
			continue;
		}
		int daybuy = s - s / 7;
		int need = m * s; // so luong thuc can thiet trong s ngay
		if(n * daybuy < m * s) // so luong thuc mua duoc trong s ngay < so luong thuc toi thieu trong s ngay
		{
			 cout << "-1" << endl;
			 continue;
		}
		if(need % n == 0) cout << need / n << endl;
		else cout << need / n + 1 << endl;
	}
}