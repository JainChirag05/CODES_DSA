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

int solve(Node *root , int *res)
{
	if(root == NULL)
	{
		return INT_MAX;
	}

	if(root->left == NULL && root->right == NULL)
	{
		return root->data;
	}

	int val = min(solve(root->left , res) , solve(root->right , res));

	*res = max(*res , root->data - val);

	return min(val , root->data);	
}

int final(Node *root)
{
	int res = INT_MIN;

	solve(root , &res);

	return res;
}

int main()
{
    // Making above given diagram's binary tree
    Node* root;
    root = newNode(8);
    root->left = newNode(3);
 
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
 
    printf("Maximum difference between a node and"
           " its ancestor is : %d\n", final(root));
}