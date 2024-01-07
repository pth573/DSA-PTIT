#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
	int data;
	node* l;
	node* r;
	node(int x)
	{
		data = x;
		l = r = NULL;
	}
	node()
	{
		l = r = NULL;
	}
};


int findInd(int inOrder[], int x, int start, int end)
{
	for(int i = start; i <= end; i++)
	{
		if(x == inOrder[i]) return i;
	}
	return -1;
}

// n: size of inOrder[]
// m: sizeof newLevel
int *newArray(int inOrder[], int levelOrder[], int m, int n)
{
	int* Array = new int[m];
	int j = 0;
	for(int i = 0 ; i < n; i++)
	{
		if(findInd(inOrder, levelOrder[i], 0 , m - 1) != -1)
		{
			Array[j] = levelOrder[i];
			j++;
		}
	}
	return Array;
}



node* buildTree(int inOrder[], int levelOrder[], int inStart, int inEnd, int sz)
{
	if(inStart > inEnd) return NULL;
	node* root = new node(levelOrder[0]);
	if(inStart == inEnd) return root;
	
	int inInd = findInd(inOrder, root->data, inStart, inEnd);
	
	int* rootLeft = newArray(inOrder, levelOrder, inInd, sz); // sz: sz cua level ben trai
	int* rootRight = newArray(inOrder + inInd + 1,  levelOrder, sz - 1, sz); // sz: sz cua Lever ben phai
	// ?? 
	root-> l = buildTree(inOrder, rootLeft, inStart, inInd - 1, inInd - inStart);
	root-> r = buildTree(inOrder, rootRight, inInd + 1, inEnd, inEnd - inInd);
	delete[] rootLeft;
	delete[] rootRight;
	return root;
}

void printPostorder(node* x)
{
    if (x == NULL)
        return;
    printPostorder(x->l);
    printPostorder(x->r);
    cout << x->data << " ";
}

int main()
{
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int inOrder[n];
		int levelOrder[n];
		for(int i = 0; i < n; i++) cin >> inOrder[i];
		for(int i = 0; i < n; i++) cin >> levelOrder[i];
		node* root = buildTree(inOrder, levelOrder, 0, n - 1, n);
		printPostorder(root);
		cout << endl;
	}
}

//2
//7
//3 1 4 0 5 2 6 
//0 1 2 3 4 5 6 


