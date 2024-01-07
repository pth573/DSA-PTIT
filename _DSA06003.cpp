#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// selection  sort

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int cnt = 0;
		for(int i = 0; i < n - 1; i++)
		{
			int ind = i;
			for(int j = i + 1; j < n; j++)
			{
				if(a[j] < a[ind])
				{
					ind = j;
				}
			}
			if(a[i] > a[ind])
			{
				cnt++;
				swap(a[i], a[ind]);
			}
		}
		cout << cnt << endl;
//		for(auto x : a) cout << x << " ";
//		cout << endl;
	}
}