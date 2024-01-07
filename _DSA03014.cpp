#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans;

void eraseFunction(string s)
{
	unordered_set<string> visited;
	queue<string> q;
	q.push(s);
	visited.insert(s);
	while(!q.empty())
	{
		string x = q.front(); 
		q.pop();
		if(x.empty()) continue;
		ll tmp = cbrt((long double)stoll(x));
		if(tmp * tmp * tmp == stoll(x))
		{
			ans = max(ans, stoll(x));
		}
		string str;
		for(int i = 0; i < x.size(); i++)
		{
			str = x.substr(0, i) + x.substr(i + 1);
			if(visited.find(str) == visited.end() && str.size() > 0)
			{
				q.push(str);
				visited.insert(str);
			}
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		ans = LLONG_MIN;
		eraseFunction(s);
		if(ans == LLONG_MIN) cout << "-1" << endl;
		else cout << ans << endl;
	}
}