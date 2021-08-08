#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int num)
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
		count++;
		
		if(count == n)
		{
			cout << root->data << endl;
		}
		
		solve(root->right , n);
	}
}

int main()
{
    Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
  
    int n = 4;
  
    solve(root, n);
    return 0;
}
	
	
