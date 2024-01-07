#include <bits/stdc++.h> 
using namespace std; 
  
char* simplify(string s){ 
    int n = s.length(); 
    // 0 : tuong trung cho +
    // 1 : tuong trung cho -
  
    char* ans = new char(n);  // mang dong ans co n phan tu
    int ind = 0, i = 0; 
  
    stack<int> st; 
    st.push(0);  
    while(i < n)
    {
    	if(s[i] == '+') 
    	{
    		if(st.top() == 1) // neu truoc do la dau -  => doi dau
    		{
    			ans[ind] = '-';
				ind++; 
			}
			else // neu truoc do la dau + => giu nguyen
			{
				ans[ind] = s[i]; 
				ind++;
			}
		}
		else if(s[i] == '-') 
		{
			if(st.top() == 1) // neu truoc do la dau -  => doi dau
			{
				ans[ind] = '+';
				ind++;
			}
			else
			{
				ans[ind] = s[i]; // neu truoc do la dau + => giu nguyen
				ind++;
			}
		}
		else if(s[i] == '(')
		{
			if(s[i - 1] == '-') // neu truoc ( la dau - 
			{
				if(st.top() == 1) st.push(0); // neu truoc dau ngoac truoc la dau - => - voi - la + => push 0 
				else st.push(1);  // neu truoc dau ngoac truoc la dau + => + voi - la - => push 1 
			}
		}
		else if(s[i] == ')') st.pop(); // thuc hien xong 1 ( )
		else
		{
			ans[ind] = s[i]; // cac ki tu a b c...
			ind++;
		}
		i++;
	}
	return ans;
} 
  
int main(){ 
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		cout << simplify(s) << endl;
	}
}
