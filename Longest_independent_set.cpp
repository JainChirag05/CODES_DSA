#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int val)
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

int solve(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int exc = solve(root->left) + solve(root->right);

	int inc = 1;

	if(root->left)
	{
		inc += solve(root->left->left) + solve(root->left->right);
	}

	if(root->right)
	{
		inc += solve(root->right->left) + solve(root->right->right);
	}

	return max(exc , inc);
}

int main()
{
  	Node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    cout << "Size of the Largest"
         << " Independent Set is "
         << solve(root);
 
    return 0;
}