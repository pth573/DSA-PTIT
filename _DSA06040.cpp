#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 123456789;

void solve(int n, int m, int h, ll a[], ll b[], ll d[])
{
	int i = 0, j = 0;
	int k = 0;
	int check = 0;
	while(i < n && j < m && k < h)
	{
		if(a[i]==b[j] && b[j] == d[k])
		{
			cout << a[i] << " ";
			i++;
			j++;
			k++;
			check = 1;
		}
		else if(a[i] < b[j] && a[i] < d[k])
		{
			i++;
		}
		else if(b[j] < a[i] && b[j] < d[k])
		{
			j++;
		}
		else if(d[k] < a[i] && d[k] < b[j])
		{
			k++;
		}
		else if(a[i] > b[j] && a[i] > d[k])
		{
			j++;
			k++;
		}
		else if(b[j] > a[i] && b[j] > d[k])
		{
			i++;
			k++;
		}
		else if(d[k] > a[i] && d[k] > b[j])
		{
			i++;
			j++;
		}
	}
	if(!check) cout << "-1";
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, m, h; cin >> n >> m >> h;
		ll a[n], b[m], d[h];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		for(int i = 0; i < h; i++) cin >> d[i];
		solve(n, m, h, a, b, d);
		cout << endl;
	}
}
