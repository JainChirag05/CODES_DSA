//Any node to any node

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

	int single = max(max(l,r) + root->data , root->data);
	int combined = max(single , l+r+root->data);

	res = max(res , combined);

	return single;
}

int final (Node *root)
{
	int res = INT_MIN;
	solve(root , res);	

	return res;
}

int main(void)
{
    struct Node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    cout << "Max path sum is " << final(root);
    return 0;
}


