#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		int tmp[1005];
		for(int i = 0; i < n; i++)
		{
			if(i == 0) tmp[i] = s[i] - '0';  
			else
			{
				int x = s[i] - '0' - tmp[i - 1];
				if(x < 0) tmp[i] = 1;
				else tmp[i] = x; 
			}
		}
		for(int i = 0; i < n; i++)
		{
			cout << tmp[i];
		}
		cout << endl;
	}
}