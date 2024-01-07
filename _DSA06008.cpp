//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//int n, k;
//int x[1005];
//int sum;
//int check;
//int used[1005];
////
////void QuayLui(int i, int pos, int s, int cnt)
////{
////	if(check) return;
////	if(cnt == k)
////	{
////		check = 1;
////		return;
////	}
////	for(int j = pos; j <= n; j++)
////	{
////		if(s + x[j] <= sum && !used[j])
////		{
////			used[j] = 1;
////			if(s + x[j] == sum)
////			{
////				QuayLui(i + 1, 1, 0, cnt + 1);
////			}
////			else
////			{
////				QuayLui(i + 1, j + 1, s + x[j], cnt);
////				used[j] = 0;
////			}
////		}
////	}
////}
//
//void QuayLui(int i, int pos, int s, int cnt)
//{
//	if(check) return;
//  	if(cnt == k)
//	{
//		check = 1;
//		return;
//	}
//	for(int j = pos; j <= n; j++)
//	{
//		if(s + x[j] <= sum && !used[j])
//		{
//				s += x[j];
//				used[j] = 1;
//				if(s == sum)
//				{
//					QuayLui(i + 1, 1, 0, cnt + 1);
//				}
//				else
//				{
//					QuayLui(i + 1, j + 1, s, cnt);
//					used[j] = 0;
//				}
////				used[j] = 0; // ko phai used[j] = 0 o sau QuayLui.. do 
//				s -= x[j];
//		}
//	}
//}
//
//int main()
//{
//	int t; cin >> t;
//	while(t--)
//	{
//		memset(x, 0, sizeof(x));
//		memset(used, 0, sizeof(used));
//		
//		cin >> n >> k;
//		sum = 0;
//		check = 0;
//		for(int i = 1; i <= n; i++)
//		{	
//			cin >> x[i];
//			sum += x[i];
//		}
////		if(sum % k != 0)
////		{
////			cout << "0" << endl;
////			continue;
////		}
////		else
////		{
//			sum /= k;
//			QuayLui(1, 1, 0, 0);
//			cout << check << endl;
////		}
//	}
//}



//Bai 8: tim so cac cap pow(x,y)>pow(y,x)
#include<bits/stdc++.h> 
typedef long long int ll;
using namespace std;   
  
// Function to return count of pairs with x as one element 
// of the pair. It mainly looks for all values in Y[] where 
// x ^ Y[i] > Y[i] ^ x 
ll count(ll x, ll Y[], ll n, ll NoOfY[]) 
{ 
    // If x is 0, then there cannot be any value in Y such that 
    // x^Y[i] > Y[i]^x 
    if (x == 0) return 0; 
  
    // If x is 1, then the number of pais is equal to number of 
    // zeroes in Y[] 
    if (x == 1) return NoOfY[0]; 
  
    // Find number of elements in Y[] with values greater than x 
    // upper_bound() gets address of first greater element in Y[0..n-1] 
    ll* idx = upper_bound(Y, Y + n, x); 
    ll ans = (Y + n) - idx; 
  
    // If we have reached here, then x must be greater than 1, 
    // increase number of pairs for y=0 and y=1 
    ans += (NoOfY[0] + NoOfY[1]); 
  
    // Decrease number of pairs for x=2 and (y=4 or y=3) 
    if (x == 2)  ans -= (NoOfY[3] + NoOfY[4]); 
  
    // Increase number of pairs for x=3 and y=2 
    if (x == 3)  ans += NoOfY[2]; 
  
    return ans; 
} 
  
// Function to return count of pairs (x, y) such that 
// x belongs to X[], y belongs to Y[] and x^y > y^x 
ll countPairs(ll X[], ll Y[], ll m, ll n) 
{ 
    // To store counts of 0, 1, 2, 3 and 4 in array Y 
    ll NoOfY[5] = {0}; 
    for (ll i = 0; i < n; i++) 
        if (Y[i] < 5) 
            NoOfY[Y[i]]++; 
  
    // Sort Y[] so that we can do binary search in it 
    sort(Y, Y + n); 
  
    int total_pairs = 0; // Initialize result 
  
    // Take every element of X and count pairs with it 
    for (ll i=0; i<m; i++) 
        total_pairs += count(X[i], Y, n, NoOfY); 
  
    return total_pairs; 
} 
  
// Driver program  
int main() { 
	ll *A, *B, m, n, T; cin>>T;
	while(T--){
		cin>>m>>n; A = new ll[m]; B = new ll[n];
		for(ll i=0; i<m; i++) cin>>A[i];
		for(ll i=0; i<n; i++) cin>>B[i];
		cout<<countPairs(A, B, m, n)<<endl;
	}
}



