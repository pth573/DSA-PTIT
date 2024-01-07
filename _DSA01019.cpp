#include<bits/stdc++.h>
using namespace std;

int n, k;
int final;

int check(char a[])
{
	int i = 1;
	int cnt = 0; // dem so H lien tiep
	while(i <= n)
	{
		if(a[i]=='H')
		{
			while(a[i]=='H')
			{
				cnt++;
				i++;
			}
			if(cnt >= 2) return 0; 
		}
		cnt = 0;
		i++;
	}
	return 1;
}

void khoitao(char a[])
{
	a[1] = 'H';
	a[n] = 'A';
	for(int i = 2; i <= n - 1; i++) a[i] = 'A';
}

void sinh(char a[])
{
	int i = n - 1;
	while(i>=2&&a[i]=='H')
	{
		a[i] = 'A';
		i--;
	}
	if(i==1) final = 1;
	else a[i] = 'H';
}

void inkq(char a[])
{
	for(int i = 1; i <= n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		char a[n+1];
		final = 0;
		khoitao(a);
		while(!final)
		{
			if(check(a)) inkq(a);
			sinh(a);
		}
	}
}