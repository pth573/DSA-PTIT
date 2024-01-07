#include<bits/stdc++.h>
using namespace std;

struct node{
	string data;
	node* l;
	node* r;
	node(string c)
	{
		data = c;
		l = r = NULL;
	}
};

int solve(int x, int y, string c)
{
	if(c == "+") return x + y;
	else if(c == "-") return x - y;
	else if(c == "/") return x / y;
	else return x * y;
}

int inOrder(node* x)
{
	if(x == NULL)  return 0;
	if(x->l == NULL && x->r == NULL) return stoi(x->data);
	else
	{
		int ans = 0;
		int left, right;
		if(x->l != NULL)	left = inOrder(x->l);
		if(x->r != NULL) 	right = inOrder(x->r);
		if((x->data == "+" || x->data == "-" || x->data == "/" || x->data == "*"))
		{
			ans = solve(right, left, x->data);
		}
		return ans;
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s[n];
		for(int i = 0; i < n; i++) cin >> s[i];
		queue<node*> st;
		node* newNode = NULL; // dau cuoi cung cua s (dinh cua cay)
		for(int i = n - 1; i >= 0; i--)
		{
			if(s[i] == "+" || s[i] == "-" || s[i] == "/" || s[i] == "*")
			{
				newNode = new node(s[i]);
				node* x = st.front();
				st.pop();
				node* y = st.front();
				st.pop();
				newNode->l = x;
				newNode->r = y;
				st.push(newNode);
			}
			else
			{
				newNode = new node(s[i]);
				st.push(newNode);
			}
		}
		cout << inOrder(newNode) << endl;
		cout << endl;
	}
}