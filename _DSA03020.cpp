#include <bits/stdc++.h>
using namespace std;

using ll = long long; 
 
ll swapCount(string &s)
{
    vector<int> pos;
    for(int i = 0; i < s.size(); i++)
    {
    	if(s[i] == '[') pos.push_back(i); // luu vi tri [
 	}
 	ll balance = 0;
 	int indInPos = 0;
 	int ans = 0;
 	for(int i = 0; i < s.size(); i++)
 	{
 		if(s[i] == '[')
		{
			balance++;
			indInPos++; // vi tri cua [ phía sau
		}
		else
		{
			balance--;
		}
		
		if(balance < 0) // truong hop can swap, thua ]
		{
			ans += pos[indInPos] - i; // vi tri ] sau tru di vi tri sai hien tai 
			// -> la so doi cho tu [ dang sau dau tien den ]
			swap(s[i], s[pos[indInPos]]);
			indInPos++;
			balance = 1; // sau khi swap, tai i + 1 la ]
			// do da can bang tai i, i + 1  => balance tai i = 1 de tai i + 1 can bang (balance = 0)
		}
	}
	return ans;
}
 
int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		cout << swapCount(s) << endl;
	}
}
 