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

int height(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int l = height(root->left);
	int r = height(root->right);

	return max(l+1 , r+1);
}

bool check(Node *root)
{
	//O(n^2)

	if(root == NULL)
	{
		return true;
	}

	if(check(root->left) = false)
	{
		return false;
	}

	if(check(root->right) == false)
	{
		return false;
	}

	int l = height(root->left);
	int r = height(root->right);

	if(abs(l-r) <= 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool faster(Node *root , int &h)
{
	if(root == NULL)
	{
		return true;
	}

	int l = 0 , h = 0;

	if(check(root->left , l) = false)
	{
		return false;
	}

	if(check(root->right , r) == false)
	{
		return false;
	}

	h = max(l+1 , r+1);

	if(abs(l-r) <= 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool solve(Node *root)
{
	int h = 0;

	return faster(root , h);
}