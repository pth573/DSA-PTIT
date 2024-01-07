#include<bits/stdc++.h>
using namespace std;

int n;
int a[10005];
int x[1005];
vector<string> ans;

void QuayLui(int i, int pos)
{
	for(int j = pos; j <= n; j++)
	{
		if(a[j] >= x[i-1])
		{
			x[i] = a[j];
			string tmp ="";
			if(i>=2)
			{
				for(int k = 1; k <= i; k++)
				{
					tmp+=to_string(x[k])+ " ";
				}
//				cout << tmp << " ";
				ans.push_back(tmp);
			}
			QuayLui(i+1, j+1);
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
//	x[0] = "";
//	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	QuayLui(1, 1);
	sort(ans.begin(), ans.end());
	for(auto x : ans)
	{
		cout << x;
		cout << endl;
	}
}
