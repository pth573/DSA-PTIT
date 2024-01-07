#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

// dua vao bubble sort, so buoc la so buoc toi thieu.
// bubble sort -> dua vi tri lon nhat xuong cuoi
// tim day tang ko lien tiep max ma hieu = 1 => VD 1 2 4 3 => 1 2 3 => k la 3
// tim thong qua day tang max cua vitri phan tu a[i]
// VD:
//4 1 2 5 3  a[i] ban dau

//1 2 3 4 5 a[i] sau khi sap xep
//2 3 5 1 4  i: vi tri ban dau tuong ung
// => Max 2 3 5-> 3 day tang lien tiep
// => can doi cho n - 3 = 2 phan tu


int dp[1005];

int main()
{
	int n; cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		tmp[a[i]] = i;
	}
	int cnt = 1;
	int ans = INT_MIN;
	for(int i = 1; i < n; i++)
	{
		if(tmp[i] < tmp[i + 1])
		{
			cnt++;
			ans = max(ans, cnt);
		}
		else cnt = 1;
	}
	cout << n - ans << endl;
}