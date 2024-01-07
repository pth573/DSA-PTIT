#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int x[1005];
int sum;
int used[1005];
//vector<vector<int>> ans;
int ans;
int tmp[1005];

void QuayLui(int i, int pos, int s, int cnt)
{
	for(int j = pos; j <= n; j++)
	{
		if(s + x[j] <= sum && !used[j])
		{
			s += x[j];
			used[j] = 1;
			if(s == sum)
			{
				ans = min(ans, cnt + 1);
				QuayLui(i + 1, 1, 0, 0);
			}
			else if(ans >= s / x[j] + 1)
			{
				QuayLui(i + 1, j, s, cnt + 1);
			} 
			s -= x[j];
			used[j] = 0;
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		memset(x, 0, sizeof(x));
		memset(used, 0, sizeof(used));
		memset(tmp, 0, sizeof(tmp));
		cin >> n >> sum;
		ans = INT_MAX;
		for(int i = 1; i <= n; i++)
		{	
			cin >> x[i];
		}
		sort(x + 1, x + n + 1, greater<int>());
		QuayLui(1, 1, 0 , 0);
		if(ans != INT_MAX) cout << ans << endl;
		else cout << "-1" << endl;		
	}
}





