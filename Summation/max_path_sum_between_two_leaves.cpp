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

int solve(Node *root , int &res)
{
	if(root == NULL)
	{
		return 0;
	}

	int l = solve(root->left , res);
	int r = solve(root->right , res);

	if(root->left == NULL)
	{
		return r + root->data;
	}

	if(root->right == NULL)
	{
		return l + root->data;
	}

	int curr = l + r + root->data;

	res = max(curr , res);

	return max(l,r) + root->data;
}

int final(Node *root)
{
	int res = INT_MIN;

	solve(root , res);

	return res;
}

int main()
{
    struct Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    cout << "Max pathSum of the given binary tree is "
         << final(root);
    return 0;
}