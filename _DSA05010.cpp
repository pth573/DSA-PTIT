#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

int n, k, t, a[N], f[N][N];

int main() {
    cin >> t;
    while (t--) 
	{
        cin >> n >> k;
        for (int i = 1; i <= n; i++) 
		{
            cin >> a[i];
            a[i] %= k;
        }
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= k; j++) f[i][j] = INT_MIN; // ko duoc la 0
        }
		// f[i][j]  = chieu dai day con co tong chia cho k dai nhat tai vi tri i, voi so du khi chia cho k la j
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) // i: vi tri thu i cua mang
		{
            for (int j = 0; j < k; j++)  //  j: so du  = j
			{
                f[i][j] = max(f[i][j], f[i-1][j]); // cap nhat chieu dai day con max hien tai % k du j = chieu dai max cua vi tri truoc % k du j 
                int mod = (j + a[i]) % k; // cong vao ve tim so du moi 
				// VD: so du la j, sau khi + a[i]  % k thi mod bayh la so du sau khi cong a[i] (tong cac a[i] % k == mod) 
				// => can tim chieu dai day con max hien tai sau khi + a[i] thi se bang chieu dai day con max truoc co cung mod  + 1
                f[i][j] = max(f[i][j], f[i-1][mod]+1); // chieu dai max tai vi tri hien tai  = 
            }
        }
        cout << f[n][0] << endl;
    }
}