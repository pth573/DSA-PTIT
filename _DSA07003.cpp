#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 123456789;

int solve(string s)
{
	stack<char> st;
	for(int i = 0; i < s.size(); i++)
	{
		if(st.empty()||s[i]!=')') st.push(s[i]);
		else
		{
			int check = 0;
			while(st.top()!='(')
			{
				char x = st.top();
				if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^') check = 1;
				st.pop();
			}
			if(check == 0) return 1;
			st.pop();
		}	
	} 
	return 0;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		if(solve(s)) cout << "Yes" << endl;
		else cout << "No" <<  endl;
	}
}