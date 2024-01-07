#include<bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n, k; cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int largest = INT_MIN;
		for(int i = 0; i <= n - k; i++)
		{
			if(a[i + k - 1] < largest || i == 0)
			{
				int tmp = INT_MIN;
				for(int j = i; j < i + k; j++)
				{
					tmp = max(tmp, a[j]);
				}
				a[i] = tmp;
				largest = tmp;
			}
			else
			{
				a[i] = a[i + k - 1];
				largest = a[i + k - 1];
			}
		}
		for(int i = 0; i <= n - k; i++) cout << a[i] << " ";
		cout << endl;
	}
}