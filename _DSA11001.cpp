#include<bits/stdc++.h>
using namespace std;

struct node{
	char data;
	node* l;
	node* r;
	node(char c)
	{
		data = c;
		l = r = NULL;
	}
};

void inOrder(node* x)
{
	if(x == NULL)  return;
	else
	{
		inOrder(x->l);
		cout << x->data;
		inOrder(x->r);
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		stack<node*> st;
		node* newNode = NULL; // dau cuoi cung cua s (dinh cua cay)
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
			{
				newNode = new node(s[i]);
				node* x = st.top();
				st.pop();
				node* y = st.top();
				st.pop();
				newNode->l = y;
				newNode->r = x;
				st.push(newNode);
			}
			else
			{
				newNode = new node(s[i]);
				st.push(newNode);
			}
		}
		inOrder(newNode);
		cout << endl;
	}
}