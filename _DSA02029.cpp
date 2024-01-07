#include<bits/stdc++.h>
using namespace std;

void tower(int n, char initial, char tmp, char desti)
{
	if(n==1)
	{
		cout << initial << " -> " << desti << endl;
		return;
	}
	else
	{
		tower(n - 1, initial, desti, tmp);
		cout << initial << " -> " << desti << endl;		
		tower(n - 1, tmp, initial, desti); // ko can in do luon de quy den truong hop n==1
	}
}

int main()
{
	int n;
	cin >> n;
	tower(n, 'A', 'B', 'C');
}
