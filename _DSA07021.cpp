#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(string s)
{
    int n = s.length();
    stack<int> st;
    st.push(-1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            if (!st.empty())
                result = max(result, i - st.top());
            else
                st.push(i);
        }
    }
    return result;
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		cout << solve(s) << endl;
	}
}



//#include<bits/stdc++.h>
//
//using namespace std;
//using ll = long long;
//
//int solve(string s, int n)
//{
//    int left = 0, right = 0, maxlength = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '(') left++;
//        else right++;
//        if (left == right)
//            maxlength = max(maxlength, 2 * right);
//        else if (right > left)
//            left = right = 0;
//    }
//    left = right = 0;
//    
//    
//    for (int i = n - 1; i >= 0; i--) 
//	{
//        if (s[i] == '(') left++;
//        else right++;
//        if (left == right)
//            maxlength = max(maxlength, 2 * left);
//        else if (left > right)
//            left = right = 0;
//    }
//    return maxlength;
//}
//
//int main()
//{
//	int t; cin >> t;
//	while(t--)
//	{
//		string s; cin >> s;
//		cout << solve(s, s.size()) << endl;
//	}
//}

