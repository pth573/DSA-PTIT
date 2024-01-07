#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int x[1005];
int sum;
int check;
int used[1005];
//
//void QuayLui(int i, int pos, int s, int cnt)
//{
//	if(check) return;
//	if(cnt == k)
//	{
//		check = 1;
//		return;
//	}
//	for(int j = pos; j <= n; j++)
//	{
//		if(s + x[j] <= sum && !used[j])
//		{
//			used[j] = 1;
//			if(s + x[j] == sum)
//			{
//				QuayLui(i + 1, 1, 0, cnt + 1);
//			}
//			else
//			{
//				QuayLui(i + 1, j + 1, s + x[j], cnt);
//				used[j] = 0;
//			}
//		}
//	}
//}

void QuayLui(int i, int pos, int s, int cnt)
{
	if(check) return;
  	if(cnt == k)
	{
		check = 1;
		return;
	}
	for(int j = pos; j <= n; j++)
	{
		if(s + x[j] <= sum && !used[j])
		{
				s += x[j];
				used[j] = 1;
				if(s == sum)
				{
					QuayLui(i + 1, 1, 0, cnt + 1);
				}
				else
				{
					QuayLui(i + 1, j + 1, s, cnt);
				}
				used[j] = 0; // ko phai used[j] = 0 o sau QuayLui.. do 
				s -= x[j];
		}
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		memset(x, 0, sizeof(x));
		memset(used, 0, sizeof(used));
		
		cin >> n >> k;
		sum = 0;
		check = 0;
		for(int i = 1; i <= n; i++)
		{	
			cin >> x[i];
			sum += x[i];
		}
		if(sum % k != 0)
		{
			cout << "0" << endl;
			continue;
		}
		else
		{
			sum /= k;
			QuayLui(1, 1, 0, 0);
			cout << check << endl;
		}
	}
}


