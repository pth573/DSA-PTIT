#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		stack<int> st;
		string ans = "";
		for(int i = 0; i <= s.size(); i++)
		{
			st.push(i + 1);
			if(i == s.size() N|| s[i] == 'I')
			{
				while(!st.empty())
				{
					ans = ans + to_string(st.top());
					st.pop();
				}
			}
		}
		cout << ans << endl;
	}
}
