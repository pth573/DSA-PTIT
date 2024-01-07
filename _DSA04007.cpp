#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

void equal_sz(string &a, string &b)
{
	int sz = max(a.size(), b.size());
	while(a.size() < sz) a = "0" + a;
	while(b.size() < sz) b = "0" + b;	
}

string sum(string a, string b, int k)
{
	equal_sz(a, b);
    int carry = 0;
    string res;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        int d = (a[i] - '0') + (b[i] - '0') + carry;
        
        carry = d / k;
        res = (char)(d % k + '0') + res;
	}    
    if (carry) res = '1' + res;    
    return res;
}


int main()
{
	int t; cin >> t;
	while(t--)
	{
		int k;
		string a, b; cin >> k >> a >> b;
		string ans = sum(a, b, k);
		cout << ans << endl;
	}
}


