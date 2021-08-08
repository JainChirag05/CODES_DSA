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

int solve(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	return solve(root->left) + height(root) + solve(root->right);
}

int main()
{
    Node* root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("Sum of heights of all Nodes = %d",   
                        solve(root));
    return 0;
}