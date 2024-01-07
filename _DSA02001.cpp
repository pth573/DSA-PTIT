#include<bits/stdc++.h>
using namespace std;



void inkq(int a[], int n)
{
	cout << "[";
	for(int i = 1; i < n; i++) cout << a[i] << " ";
	cout << a[n] << "]" << endl;
}

void solve(int a[], int n)
{
//	inkq(a, n); // neu cai nay thi dki duoi if(n==1)
	if(n==0)
	{
		return;
	}
//	inkq(a, n) // ok
	int tmp[n-1]; // chu y 
	for(int i = 1; i < n; i++)
	{
		int x = a[i] + a[i+1];
		tmp[i] = x;
	}
	inkq(a, n);
	solve(tmp, n - 1);
//	inkq(a, n); // nguoc lai
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int a[n];
		for(int i = 1; i <= n; i++) cin >> a[i];
		solve(a, n);
	}
}

