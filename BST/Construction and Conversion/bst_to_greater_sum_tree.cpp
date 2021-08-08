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

void solve(Node *root , int *sum)
{
	//reverse inorder for bst

	if(root == NULL)
	{
		return;
	}

	solve(root->right , sum);

	*sum += root->data;

	root->data = *sum - root->data;

	solve(root->left  , sum);
}

void final(Node *root)
{
	int sum = 0;

	solve(root , &sum);
}

int main()
{
    Node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);
 
    cout << "Inorder Traversal of given tree\n";
    inorder(root);
 
    final(root);
 
    cout << "\n\nInorder Traversal of transformed tree\n";
    inorder(root);
 
    return 0;
}