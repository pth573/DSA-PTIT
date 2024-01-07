#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int x[1005];

void backTracking(int i, int sum)
{
	for(int j = x[i - 1]; j >= 1; j--)
	{
		if(sum + j <= n)
		{
			sum += j;
			x[i] = j;
			if(sum == n)
			{
				cout << "(";
				for(int k = 1; k < i; k++)
				{
					cout << x[k] << " ";
				}
				cout << x[i] << ")";
				cout << " ";
			}
			else
			{
				backTracking(i + 1, sum);
			}
			sum -= j;
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		memset(x, 0, sizeof(x));
		cin >> n;
		x[0] = n;
		backTracking(1, 0);
		cout << endl;
	}
}
