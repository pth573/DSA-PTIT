#include<bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int xuoi[1005], nguoc[1005], ngang[1005], doc[1005];
int ans = INT_MIN;
int x[1005][1005];

void QuayLui(int i)
{
	for(int j = 0; j < n; j++)
	{
		if(!xuoi[i+j-1]&&!nguoc[n-i+j]&&!ngang[i+1]&&!doc[j])
		{
			a[i] = j;
			if(i==n-1)
			{
				int sum = 0;
				for(int k = 0; k <= i; k++)
				{
					sum += x[k][a[k]];
				}
				ans = max(ans, sum);
			}
			xuoi[i+j-1] = nguoc[n-i+j] = ngang[i] = doc[j] = 1;
			QuayLui(i+1);
			xuoi[i+j-1] = nguoc[n-i+j] = ngang[i] = doc[j] = 0;
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		n = 8;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++) cin >> x[i][j];
		}
		QuayLui(0);
		cout << ans << endl;
		memset(a, 0, sizeof(a));
		ans = INT_MIN;
	}
}

