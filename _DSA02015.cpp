
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> ans;

int isDifLetter(char x)
{
	if(x == '(' || x == ')') return 1;
	else return 0;
}

int isValid(string s)
{
	if(s.empty()) return 0;
	if(s.size() == 1 && isalpha(s[0])) return 0;
	int cnt = 0;
	for(auto x : s)
	{
		if(x == '(') cnt++;
		else if(x == ')') cnt--;
		if(cnt < 0) return 0;
	}
	return cnt == 0;
}

void eraseValid(string s)
{
	if(!s.size()) return;
	unordered_set<string> visited;
	queue<string> q;
	q.push(s);
	visited.insert(s);
	int check = 0;
	while(!q.empty())
	{
		string x = q.front(); 
		q.pop();
		if(isValid(x)) // neu la xau hop le => push vao ket qua
		{
			ans.push_back(x);
			check = 1;
		}
		if(check) continue;
		for(int i = 0; i < x.size(); i++)
		{
			if(isDifLetter(x[i]))
			{
				string tmp = ""; // xoa ki tu thu i
				tmp = x.substr(0, i) + x.substr(i + 1);
				if(visited.find(tmp) == visited.end() && tmp.size() > 0)
				{
					q.push(tmp);
					visited.insert(tmp);
				}
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
		eraseValid(s);
		if(ans.size())
		{
			sort(ans.begin(), ans.end());
			for(auto x : ans)
			{
				cout << x << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
		ans.clear();
	}
}