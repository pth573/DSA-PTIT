#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1005][1005];
int cnt;
int xuoi[1005], nguoc[1005], ngang[1005], doc[1005];

int ans = 0;

void QuayLui(int i)
{
	for(int j = 0; j < n; j++)
	{
		if(!xuoi[i+j-1]&&!nguoc[n-i+j]&&!ngang[i+1]&&!doc[j])
		{
			if(i==n-1)
			{
				ans++;
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
		cin >> n;
		cnt = 0;
		QuayLui(0);
		cout << ans << endl;
		ans = 0;
	}
}


