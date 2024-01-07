#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int x[1005];
int n;
int final;

void khoitao()
{
	for(int i = 1; i <= n; i++)
	{
		x[i] = 0;
	}
}

void Sinh()
{
	int i = n;
	while(i >= 1 && x[i] == 1)
	{
		x[i] = 0;
		i--;
	}
	if(i == 0) final = 1;
	else x[i] = 1;
}


void change()
{
	int tmp[n + 1];
	for(int i = 1; i <= n; i++)
	{
		if(i == 1) tmp[i] = x[i];
		else
		{
			int sum = x[i] + x[i - 1];
			if(sum == 2) tmp[i] = 0;
			else
			{
				tmp[i] = sum;
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << tmp[i];
	cout << " ";
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		khoitao();
		final = 0;
		while(!final)
		{
			change();
			Sinh();
		}
		cout << endl;
		memset(x, 0, sizeof(x));
	}
}