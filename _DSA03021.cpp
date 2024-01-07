#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
 
int main()
{
	int n; cin >> n;
	int smallest = INT_MAX;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		smallest = min(smallest, a[i]);
	}
	int Min = INT_MAX;
	for(int i = smallest; i >= 1; i--)
	{
		int tmp; // luu a[j] / j;
		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			if(j == 0)
			{
				tmp = a[j] / i;
				int k = (a[j] / (tmp + 1)) + 1; // tmp <= [ a[j] / i ] < tmp + 1;
				sum += k;
			}
			else
			{
				int low = (a[j] / (tmp + 1)) + 1;
				if(a[j] / low >= tmp) // check dkien tmp <= [ a[j] / i ]
				{
					sum += low;
				}
				else break;
			}
			if(sum < Min && j == n - 1)
			{
				Min = min(Min, sum);
			}
			if(sum >= Min) break;
		}
	}
	cout << Min << endl;
}