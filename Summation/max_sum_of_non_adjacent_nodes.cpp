#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	//int store;
	Node *left;
	Node *right;
};

Node *newNode(int val)
{
	Node *temp = new Node();
	temp->left = temp->right = NULL;

	temp->data = val;
	//temp->store = 0;

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

int recur(Node *root)
{
	//exp complexity

	if(root == NULL)
	{
		return 0;
	}

	int ex = solve(root->left) + solve(root->right);

	int in = root->data;

	if(root->left)
	{
		in += solve(root->left->left) + solve(root->left->right);
	} 

	if(root->right)
	{
		in += solve(root->right->left) + solve(root->right->right);
	}

	return max(ex , in);
}

unordered_map <Node* , int> dp;

int solve(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	if(dp[root])
	{
		return dp[root];
	}

	int in = root->data;

	if(root->left)
	{
		in += solve(root->left->left) + solve(root->left->right);
	}

	if(root->right)
	{
		in += solve(root->right->left) + solve(root->right->right);
	}

	int ex = solve(root->left) + solve(root->right);

	dp[root] = max(in , ex);

	return dp[root];

}

