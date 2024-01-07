#include <bits/stdc++.h>
using namespace std;

void equal_sz(string &a, string &b)
{
	int sz = max(a.size(), b.size());
	while(a.size() < sz) a = "0" + a;
	while(b.size() < sz) b = "0" + b;	
}

string add(string a, string b, int k)
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

void del_zero(vector<int> &a) 
{ 
    reverse(a.begin(), a.end()); 
    while (a.size() >= 2) 
        if (a.back() == 0) 
            a.pop_back();
        else 
            break;
    reverse(a.begin(), a.end());
}

string multi(string x, string y)
{
	vector<int> a;
	vector<int> b;
	for(int i = 0; i < x.size(); i++) a.push_back(x[i] - '0');
	for(int i = 0; i < y.size(); i++) b.push_back(y[i] - '0');	
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> c(a.size() + b.size() + 1);
    for (int i = 0; i < (int) a.size(); ++i)
        for (int j = 0; j < (int) b.size(); ++j)
        {
            c[i + j] += (a[i] * b[j]);
            c[i + j + 1] += (c[i + j] / 10);
            c[i + j] %= 10;
        }
    c.push_back(0);
    for (int i = 0; i < (int) c.size() - 1; ++i) 
    {
    	c[i + 1] += (c[i] / 10);
    	c[i] %= 10;
    }

    reverse(c.begin(), c.end());
    del_zero(c);
    string tmp = "";
    for(int i = 0; i < c.size(); i++)
    {
    	tmp = "" + tmp + to_string(c[i]);
	} 
    return tmp;
}

string catalan(int n) 
{
	string dp[n + 1];
	dp[0] = "1";
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			dp[i] = add(dp[i], multi(dp[j], dp[i - j - 1]), 10);
		}
	}
	return dp[n];
}
int main() 
{
	int t;
	cin >> t;
	while (t--) 
	{
		int n;
		cin >> n;
		else if(n > 0) 
		{
			cout << catalan(n) << endl;
		}
	}
}

