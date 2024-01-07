#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int a[n];
		stack<pair<int, int>> st;
		int ans[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			ans[i] = 1;
		}
		for(int i = 0; i < n; i++)
		{
			while(!st.empty() && st.top().first <= a[i])
			{
				ans[i] += st.top().second; 
				st.pop();
			}
			st.push({a[i], ans[i]});
		}
		for(int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << endl;
	}
}