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

void solve(Node *root , int k)
{
	if(root == NULL || k < 0)
	{
		return;
	}

	if(k == 0)
	{
		cout << root->data << " ";
	}

	solve(root->left , k-1);
	solve(root->right , k-1);
}

int main()
{
 
    /* Constructed binary tree is
            1
            / \
        2     3
        / \     /
        4 5 8
    */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(8);
     
    solve(root, 2);
    return 0;
}

