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

int sum = 0;

int solve(Node *root , int x)
{
	if(root == NULL)
	{
		return 0;
	}

	if((root->left && root->left->data == x) || (root->right && root->right->data == x))
	{
		sum += root->data;
	}

	solve(root->left , x);
	solve(root->right , x);

	return sum;
}

int main()
{
    // binary tree formation
    Node *root = getNode(4);           /*        4        */
    root->left = getNode(2);           /*       / \       */
    root->right = getNode(5);          /*      2   5      */
    root->left->left = getNode(7);     /*     / \ / \     */
    root->left->right = getNode(2);    /*    7  2 2  3    */
    root->right->left = getNode(2);
    root->right->right = getNode(3);
      
    int x = 2;
      
    cout << "Sum = "
         << solve(root, x);
           
    return 0;    
} 