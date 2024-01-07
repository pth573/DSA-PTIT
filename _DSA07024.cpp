#include <bits/stdc++.h>
using namespace std;


int main() 
{
	int t; cin >> t;
	while(t--)
	{
		int n;
	    cin >> n;
	    int a[n];
	    stack<int> st;
	    for(int i = 0; i < n; i++)
	    {
	        cin >> a[i];
	    }
	    int i = 0;
	    long long ans = INT_MIN;
	    while(i < n)
	    {
	        if(st.empty()||a[i] >= a[st.top()])
	        {
	            st.push(i);
	            i++;
	        }
	        else
	        {
	            int top = st.top();
	            st.pop();
	            long long s = 0;
	            if(st.empty())
				{
					if(a[top] <= i)
					{
						s = min(a[top], i) * min(a[top], i);
//						ans = max(ans, s);
					}	
				} //s = 1ll * a[top] * i;
	            else
	            {
	            	if(a[top] <= i - 1 - st.top())
	            	{
	            		s = min(a[top], i - 1 - st.top()) * min(a[top], i - 1 - st.top());
//	            		ans = max(ans, s);
					}
	//            	 s = 1ll * a[top] * (i - 1 - st.top());
				}
				ans = max(ans, s);
	        }
	    }
	    while(!st.empty())
	    {
	            int top = st.top();
	            st.pop();
	            long long s = 0;
	            if(st.empty())
				{
					if(a[top] <= i)
					{
						s = min(a[top], i) * min(a[top], i);
//						ans = max(ans, s);
					}	
				} 
	            else
	            {
	            	if(a[top] <= i - 1 - st.top())
	            	{
	            		s = min(a[top], i - 1 - st.top()) * min(a[top], i - 1 - st.top());
//	            		ans = max(ans, s);
					}
				}
				ans = max(ans, s);
	    }
	    cout << sqrt(ans) << endl;
	}
}