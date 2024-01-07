#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int x[1005];
int a[1005];
int n;
int ok;
vector<vector<int>> ans;
//vector<string> ans;

int check(int x)
{
	if(x % 2 != 0) return 1;
	else return 0;
}

void QuayLui(int i, int pos, int sum)
{
	for(int j = pos; j >= 1; j--)
	{
		x[i] = a[j];
		sum += a[j];
		if(check(sum))
		{
			vector<int> v;
			for(int k = 1; k <= i; k++)
			{
				v.push_back(x[k]);
			}
			ans.push_back(v);
		}
		if(i < n)
		{
				QuayLui(i + 1, j - 1, sum);
				sum -= x[i];
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		set<int> s;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s.insert(a[i]);
		}
		memset(a, 0, sizeof(a));
		n = s.size();
		int i = 1;
		for(auto x : s)
		{
			a[i] = x;
			i++;
		}
		QuayLui(1, n, 0);
		sort(ans.begin(), ans.end());
		for(auto x : ans)
		{
			sort(x.begin(), x.end(), greater<int>());
			for(auto tmp : x) cout << tmp << " ";
			cout << endl;
		}
		ans.clear();
		memset(a, 0, sizeof(a));
		memset(x, 0, sizeof(x));
	}
}

