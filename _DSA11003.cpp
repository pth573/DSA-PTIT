#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//int findInd(int in[], int x, int sz)
//{
//	for(int i = 0; i < sz; i++)
//	{
//		if(in[i] == x) return i;
//	}
//	return -1;
//}
//
//// vi tri dau tien cua pre la bi tri cuoi cung cua post
//void postOrder(int inOrder[], int preOrder[], int sz)
//{
//	int root = findInd(inOrder, preOrder[0], sz); // tim vi tri dau tien cua pre[0] (goc cua cay hoac la goc cua tung node )
//	// neu ben trai root van co node -> tiep tuc tim
//	if(root != 0) postOrder(inOrder, preOrder + 1, root);
//	// neu ben phai root van co node -> tiep tuc tim
//	// phan tu dau tien cua pre la phan tu  pre + root tim duoc o in[] + 1
//	if(root != sz - 1) postOrder(inOrder + root + 1, preOrder + root + 1, sz - root - 1);
//	cout << preOrder[0] << " "; // phan tu goc dau tien ma tim xong ben trai khong co ,ben phai khong co=> in ra trai, phai
//}


struct node{
	int data;
	node* l;
	node* r;
	node(int x)
	{
		data = x;
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

int *newArray(int inOrder[], int levelOrder[], int n, int m)
{
	int* Array = new int[n];
	int j = 0;
	for(int i = 0 ; i < m; i++)
	{
		if(findInd(inOrder, levelOrder[i], 0 , n - 1) != -1)
		{
			Array[j] = inOrder[i];
			j++;
		}
	}
	return Array;
}



node* buildTree(int inOrder[], int levelOrder[], int inStart, int inEnd, int sz)
{
	if(inStart < inEnd) return NULL;
	node* root = new node(levelOrder[0]);
	int inInd = findInd(inOrder, root->data, inStart, inEnd);
	if(inStart == inEnd) return root;
	
	int* rootLeft = newArray(inOrder, levelOrder, inInd, sz); // sz: sz cua level ben trai
	int* rootRight = newArray(inOrder + inInd + 1,  levelOrder, inInd + 1, sz); // sz: sz cua Lever ben phai
	
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
//		postOrder(inOrder, preOrder, n);	
		node* root = new node(levelOrder[0]);
		printPostorder(root);
		cout << endl;
	}
}