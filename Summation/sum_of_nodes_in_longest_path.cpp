#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *getNode(int val)
{
	Node *temp = new Node();
	temp->left = temp->right = NULL;

	temp->data = val;

	return temp;
}

void inorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void solve(Node *root , int sum , int len , int &ms , int &ml)
{
	if(root == NULL)
	{
		return;
	}

	if(root->left == NULL && root->right == NULL && len >= ml && sum + root->data >= ms)
	{
		ml = len;
		ms = sum + root->data;
		return;
	}

	solve(root->left , sum+root->data , len+1 , ms , ml);
	solve(root->right , sum+root->data , len+1 , ms , ml);
}

int final(Node *root)
{
	int ml = 0;
	int ms = 0;

	solve(root,0,0,ms,ml);

	return ms;
}

int main()
{
    // binary tree formation
    Node* root = getNode(4);         /*        4        */
    root->left = getNode(2);         /*       / \       */
    root->right = getNode(5);        /*      2   5      */
    root->left->left = getNode(7);   /*     / \ / \     */
    root->left->right = getNode(1);  /*    7  1 2  3    */
    root->right->left = getNode(2);  /*      /          */
    root->right->right = getNode(3); /*     6           */
    root->left->right->left = getNode(6);
 
    cout << "Sum = "
         << final(root);
 
    return 0;
}