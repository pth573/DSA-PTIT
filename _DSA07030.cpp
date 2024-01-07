
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int ans;
int x[1001][1001];

void solve(int x[])
{
	stack<int> st;
	int i = 1;
	while(i <= m)
	{
		if(st.empty() || x[i] >= x[st.top()])
		{
			st.push(i);
			i++;
		}
		else
		{
			int top = st.top();
			st.pop();
			int tmp;
			if(st.empty())
			{
				tmp = x[top] * i;
			}
			else
			{
				tmp = x[top] * (i - st.top() - 1);
			}
			ans = max(ans, tmp);
		}
	}
	while(!st.empty())
	{
			int top = st.top();
			st.pop();
			int tmp;
			if(st.empty())
			{
				tmp = x[top] * i;
			}
			else
			{
				tmp = x[top] * (i - st.top() - 1);
			}
			ans = max(ans, tmp);
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		ans = INT_MIN;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++) cin >> x[i][j];
		}
		for(int i = 2; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(x[i][j]) x[i][j] += x[i - 1][j];
			}
		}
//		for(int i = 1; i <= n; i++)
//		{
//			for(int j = 1; j <= m; j++) cout << x[i][j] << " ";
//			cout << endl;
//		}
		for(int i = 1; i <= n; i++)
		{
			solve(x[i]);
		}	
		cout << ans << endl;	
	}
}