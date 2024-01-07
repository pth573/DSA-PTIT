#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int numDecodings(string s) 
{
    if(s[0] == '0') return 0;
    vector<int> DP(s.size() + 1, 1);
    for(int i = 2; i < s.size() + 1; i++) 
	{
        if(s[i - 1] != '0') DP[i] = DP[i - 1]; 
		else DP[i] = 0;
		if(s[i - 2] != '0' && stoi(s.substr(i - 2, 2)) <= 26)
		{
			DP[i] += DP[i - 2];
		}
		else DP[i] += 0;
    }  
    return DP[s.size()];    
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << numDecodings(s) << endl;
	}
}