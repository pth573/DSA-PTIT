#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int used[2000];
int n;
//vector<vector<int>> ans;
string ans[2000];
int kq = INT_MAX;
int x[2000];

int check(int x, int y)
{
	int dem = 0;
	string tmp1 = ans[x];
	string tmp2 = ans[y];
	int n = tmp1.size();
	int m = tmp2.size();
	int h = 0, k = 0;
	while(h < n && k < m)
	{
		if(tmp1[h] == tmp2[k])
		{
			dem++;
//			if(dem >= kq) return 0;
			h++; k++;
		}
		else if(tmp1[h] > tmp2[k]) k++;
		else h++;
	}
	return dem;
}

void QuayLui(int i, int sum)
{
	if(sum >= kq) return;
	for(int j = 1; j <= n; j++)
	{
		
		if(!used[j])
		{
			x[i] = j;
			used[j] = 1;
			int tmp = 0;
			if(i >= 2)
			{
				tmp = check(x[i], x[i - 1]);
				sum += tmp;
//				if(sum >= kq)
//				{
//					return; // neu o day thi return luon chua kip sum-=..
//				}
			}
			if(i == n)
			{
				kq = min(kq, sum);
			}
			if(i < n) QuayLui(i + 1, sum);
			used[j] = 0;
			sum -= tmp;
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> ans[i];
	}
	QuayLui(1, 0);
	cout << kq << endl;
}


//10
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
//ABCABCABCABCABCABCABCABCAB
