#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, s;
int a[10005];

int cnt = 0;
int ans = INT_MAX;

void QuayLui(int i, int pos, ll sum)
{
	for(int j = pos; j < n; j++)
	{
		if(sum + a[j] <= s)
		{
			sum += a[j];
			cnt++;
			if(sum == s)
			{
				ans = min(ans, cnt);
			}
			else if(ans >= sum / a[j])
			{
				QuayLui(i + 1, j + 1, sum);
				cnt--;
				sum -= a[j];
			}
		}
	}
}


int main()
{
	cin >> n >> s;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	QuayLui(0, 0, 0);
	if(ans != INT_MAX) cout << ans << endl;
	else cout << "-1" << endl;
}

