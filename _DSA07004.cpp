#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 123456789;

int solve(string s)
{
	stack<char> st;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i]=='(') st.push(s[i]);
		else
		{
			if(!st.empty()&&st.top()=='(') st.pop();
			else
			{
				cnt++;
				st.push('('); 
			}
		}
	}
	cnt += st.size()/2;
	return cnt;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		cout << solve(s) << endl;
	}
}