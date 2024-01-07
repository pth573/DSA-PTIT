 #include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int a[1001][1001];
int c = INT_MAX;
int ans = INT_MAX;
int used[1005];
int x[1005];
int kq[1005];

void solve(int i, int sum)
{
	for(int j = 2; j <= n; j++)
	{
		if(used[j] == 0)
		{
			used[j] = 1;
			x[i] = j;
			sum += a[x[i - 1]][x[i]];
 			int g = sum + (n - i + 1) * c;
			if(i == n)
			{
				if(sum + a[x[i]][1] < ans)
				{
					for(int k = 1; k <= n; k++)
					{
 						kq[k] = x[k];
					}
					ans = sum + a[x[i]][1];
				}
			}
			else if(i < n && g < ans)
			{
				solve(i + 1, sum);
			}
			used[j] = 0;
			sum -= a[x[i - 1]][x[i]];
		}
	}
}



int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(i != j) c = min(c, a[i][j]);
		}
	}
	x[1] = 1;
	used[1] = 1;
	solve(2, 0);
	cout << ans << endl;
}



