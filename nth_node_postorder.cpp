#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *createNode(int num)
{
	Node *temp = new Node();
	
	temp->data = num;
	temp->left = temp->right = NULL;
	
	return temp;
}

void solve(Node *root , int n)
{
	static int count = 0;
	
	if(root == NULL)
	{
		return;
	}
	
	if(count <= n)
	{
		solve(root->left , n);
		
		solve(root->right , n);
		
		count++;
		
		if(count == n)
		{
			cout << root->data << endl;
		}
	}
}


int main()
{
	Node* root = createNode(25);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(18);
    root->left->right = createNode(22);
    root->right->left = createNode(24);
    root->right->right = createNode(32);
  
    int N = 6;
  
    // prints n-th node found
    solve(root, N);
  
    return 0;
}


