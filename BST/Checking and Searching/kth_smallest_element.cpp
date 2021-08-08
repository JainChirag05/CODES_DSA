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

Node *search(Node *root , int val)
{
	if(root->data == val)
	{
		return root;
	}

	if(root->data < val)
	{
		return search(root->right , val);
	}

	else
	{
		return search(root->left , val);
	}
}

Node *solve_extra_space(Node *root , int &k)
{
	if(root == NULL)
	{
		return NULL;
	}

	Node *left = solve_extra_space(root->left , k);

	if(left != NULL)
	{
		return left;
	}

	k--;

	if(k == 0)
	{
		return root;
	}

	return solve_extra_space(root->right , k);
}

Node *solve_no_extra_space(Node *root , int &k)
{
	
}