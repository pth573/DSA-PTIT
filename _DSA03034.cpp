#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

const int mod2 = 123456789;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, m, k; cin >> n >> m >> k;
		int a[n];
		int b[m];
		int c[k];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		for(int i = 0; i < k; i++) cin >> c[i];
		int i = 0, j = 0, h = 0;
		int cnt = 0;
		while(i<n&&j<m&&h<k)
		{
			if(a[i]==b[j]&&b[j]==c[h])
			{
				cnt++;
				cout << a[i] << " ";
				i++; j++; h++;
			}
			if(a[i]<b[j]) i++;
			else if(b[j]<c[h]) j++;
			else if(c[h]<a[i]) h++;
		}
		if(cnt==0) cout << "NO";
		cout << endl;
	}
}
