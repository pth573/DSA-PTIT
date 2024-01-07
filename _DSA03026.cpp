#include<bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

int main()
{
		int s, d; cin >> d >> s;
		if(9 * d < s || d == 0)
		{
			cout << "-1 -1" << endl;
			return 0;
		}	
		if(d > 1 && s == 0)
		{
			cout << "-1 -1" << endl;
			return 0;			
		}
		int tmp = s;
		s -= 1;
		int i = d;
		int a[d + 1];
		while(s >= 0 && i >= 1)
		{
			if(s >= 9)
			{
				a[i] = 9;
				i--;
				s -= 9;
			}
			else
			{
				a[i] = s;
				s = 0;
				i--;
			}
		}
		if(tmp > 0) a[1]++;
		for(int i = 1; i <= d; i++) cout << a[i];
		cout << " ";
		memset(a, 0, sizeof(a));
		i = 1;	
		while(tmp >= 0 && i <= d)
		{
			if(tmp >= 9)
			{
				a[i] = 9;
				i++;
				tmp -= 9;
			}
			else
			{
				a[i] = tmp;
				tmp = 0;
				i++;
			}
		}
		for(int i = 1; i <= d; i++) cout << a[i];
}
