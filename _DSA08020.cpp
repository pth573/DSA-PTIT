#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int prime[10001];

void Ethanos()
{
	for(int i = 2; i <= 10000; i++) prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;
	for(int i = 2; i <= 10000; i++)
	{
		if(prime[i])
		{
			for(int j = i * i; j <= 10000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
}

int solve(string s, string t)
{
	queue<pair<string, int>> q;
	set<string> se;
	q.push({s, 0});
	se.insert(s);
	while(!q.empty())
	{
		auto x = q.front(); q.pop();
		string str = x.first;
		int step = x.second;
		if(stoi(str) == stoi(t)) return step;
		
		string tmp = str;
			for(char j ='1'; j <= '9'; j++)
			{
				tmp[0] = j;
				if(!se.count(tmp) && prime[stoi(tmp)])
				{
					q.push({tmp, step + 1});
					se.insert(tmp);
				}
			}
		
		for(int i = 1; i < str.size(); i++)
		{
			tmp = str;
			for(char j ='0'; j <= '9'; j++)
			{
				tmp[i] = j;
				if(!se.count(tmp) && prime[stoi(tmp)])
				{
					q.push({tmp, step + 1});
					se.insert(tmp);
				}
			}
		}
	}	
} 

int main()
{
	int test; cin >> test;
	Ethanos();
	while(test--)
	{
		string s, t; cin >> s >> t;
		cout << solve(s, t) << endl;
	}
}