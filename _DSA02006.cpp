#include<bits/stdc++.h>
using namespace std;

int n, s;
int x[1005];
int a[1005];
int check;

void QuayLui(int i, int sum, int pos)
{
	for(int j = pos; j < n; j++)
	{
		if(sum + a[j] <= s)
		{
			x[i] = a[j];
			sum+=a[j];
			if(sum == s)
			{
				check = 1;
				cout << "[";
				for(int k = 0; k < i; k++) cout << x[k] << " ";
				cout << x[i] << "] ";
			}
			else QuayLui(i+1, sum, j + 1);
			sum-=x[i];
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> s;
		check = 0;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		QuayLui(0, 0, 0);
		if(check==0) cout << "-1";
		cout << endl;
		memset(x, 0, sizeof(x));
		memset(a, 0, sizeof(a));
	}
}

