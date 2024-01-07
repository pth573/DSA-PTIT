#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int x[1005];
int n, p, s; 
vector<vector<int>> ans;
int cnt;

int check(int n)
{
	if(n <= p) return 0;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0) return 0;
	}
	return n > 1;
}


void QuayLui(int i, int pos, int sum)
{
	for(int j = pos; j <= s; j++)
	{
		if(check(j))
		{
			if(sum + j <= s)
			{
				x[i] = j;
				sum += j;
				if(sum == s && i == n)
				{
					cnt++;
					vector<int> v;
					for(int k = 1; k <= i; k++)
					{
						v.push_back(x[k]);
					}
					ans.push_back(v);
				}
				else QuayLui(i + 1, j + 1, sum);
				sum -= x[i];
			}
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> p >> s;
		cnt = 0;
		QuayLui(1, 1, 0);
		cout << cnt << endl;
		for(auto x : ans)
		{
			for(auto tmp : x) cout << tmp << " ";
			cout << endl;
		}
		ans.clear();
	}
}
