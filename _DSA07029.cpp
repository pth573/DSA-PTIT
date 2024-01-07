#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(string s)
{
	stack<char> st;
	string ans = "";
	for(int i = 0; i < s.size(); i++)
	{
		st.push(s[i]);
		if(s[i] == ']')
		{
			st.pop(); // vua push ] => pop ]
			string x = "";
			while(!st.empty() && st.top() != '[')
			{
				x = st.top() + x;
				st.pop();
			}
			// x : xau o trong []
			if(!st.empty()) st.pop(); // xoa [
			string str = ""; // so o truoc [
			while(!st.empty() && isdigit(st.top()))
			{
				str = st.top() + str;
				st.pop();
			}
			if(str.size()) // chu y
			{
				int tmp = stoi(str);
				tmp--; // giam do chi chi tmp - 1 lan lap lai xau
				string k = x;
				while(tmp--)
				{
					x = k + x;
				}
			}
			// VD 3[a] => x bayh la aaa
			for(auto c : x) st.push(c); // day lai vao stack de luu ket qua VD stack : 3[b2[ca]] => 3[b. caca] => 3 * bcaca 
		}
	}
	// trong stack la ket qua can tim
	while(!st.empty())
	{
		ans = st.top() + ans; 
		st.pop();
	}
	return ans;
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