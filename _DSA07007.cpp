#include <bits/stdc++.h> 
using namespace std; 
  
int v[26];

int checkSign(string s, int i) // check gia tri truoc ( la dau gi
{
	if(i == 0) return 1; // vi tri ( la dau tien
	
	if(s[i - 1] == '-') return 0;
	else return 1;
}

void check(string s, int sign)
{
	int n = s.size();
	int i = 0;
	stack<int> st;
	st.push(1);
	while(i < n)
	{
		if(s[i] == '+' || s[i] == '-')
		{
			i++;
			continue;
		}
		else if(s[i] == '(')
		{
			if(checkSign(s, i)) st.push(st.top());
			else st.push(!st.top());
		} 
		else if(s[i] == ')')
		{
			//if(!st.empty()) 
			st.pop();
		}
		else // chu
		{
			if(!st.empty() && st.top()) // +
			{
				if(checkSign(s, i)) // check truoc chu do la dau + hay -  => +
				{
					if(sign) v[s[i] - 'a'] += 1;   // sign: + 
					else v[s[i] - 'a'] -= 1;					
				}
				else  // -
				{
					if(!sign) v[s[i] - 'a'] += 1; // sign -
					else v[s[i] - 'a'] -= 1;	// sign + 
				}
			}
			else if(!st.empty() && !st.top()) // - 
			{
				if(!checkSign(s, i)) // -
				{
					if(sign) v[s[i] - 'a'] += 1; // sign: +
					else v[s[i] - 'a'] -= 1;    // sign -;		
				}
				else // + 
				{
					if(!sign) v[s[i] - 'a'] += 1; // sign -
					else v[s[i] - 'a'] -= 1;	// sign +
				}				
			}
		}
		i++;
	}
}
  
int areSame(string s, string t)
{
	check(s, 1); // de trieu tieu nhau
	check(t, 0);
	for(auto  x : v)
	{
		if(x != 0) return 0;
	}
	return 1;
}
  
int main(){ 
	int t; cin >> t;
	while(t--)
	{
//		v.clear();
		memset(v, 0, sizeof(v));
//		for(int i = 0; i < 26; i++) v[i] = 0;
		string s; cin >> s;
		string t; cin >> t;
		if(areSame(s, t)) cout  << "YES" << endl;
		else cout << "NO" << endl;
	}
}



