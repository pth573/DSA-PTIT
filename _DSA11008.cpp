#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
	int data;
	node* right;
	node* left;
	node(int x)
	{
		data = x;
		left = NULL;;
		right = NULL;
	}
};

void makeroot(node* root, int u, int v, char c)
{
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);	
}

void insert(node* root, int u, int v, char c)
{
	if(root == NULL)
	{
		return;
	}
	if(root->data == u)
	{
		makeroot(root, u, v, c);
	}
	else
	{
		insert(root->left, u, v, c);
		insert(root->right, u ,v ,c);
	}
}

int check(node* root, int h, int &height)
{
	if(root == NULL) return 1;
	if(root->left == NULL && root->right == NULL)
	{
		if(height == 0)
		{
			height = h;
			return 1;
		}
		else return h == height;
	}
	else
	{
		return(check(root->left, h + 1, height) && check(root->right, h + 1, height));
	}
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		node* root = NULL;
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			char c;
			cin >> x >> y >> c;
			if(root == NULL)
			{
				root = new node(x);
				makeroot(root, x, y, c);
			}
			else insert(root, x, y, c);
		}
		int height = 0;
		if(check(root, 0, height)) cout << "1" << endl;
		else cout << "0" << endl;
	}
}
