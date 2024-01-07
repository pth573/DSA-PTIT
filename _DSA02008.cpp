#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// hang ko trung => co the sinh moi cot theo cac hoan vi

int a[1005];
int n, s;
int final = 0;
int x[1005][1005];

void khoitao()
{
	for(int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
}

void sinh()
{
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1] ) i--;
	if(i == 0) final = 1;
	else
	{
		int ind = n;
		while(a[i] > a[ind]) ind--;
		swap(a[i], a[ind]);
		reverse(a + i + 1, a + n + 1);
	}
}

int check()
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += x[i][a[i]];
	}
	if(sum == s) return 1;
	else return 0;
}

int main()
{
	cin >> n >> s;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++) cin >> x[i][j];
	}
	khoitao();
	int cnt = 0;
	vector<vector<int>> ans;
	while(!final)
	{
		if(check())
		{
			cnt++;
			vector<int> v;
			for(int i = 1; i <= n; i++) v.push_back(a[i]);
			ans.push_back(v);
		}
		sinh();
	}
	cout << cnt << endl;
	for(auto x : ans)
	{
		for(auto tmp : x) cout << tmp << " ";
		cout << endl;
	}
}