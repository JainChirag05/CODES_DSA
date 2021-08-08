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
	if(root == NULL)
	{
		return;
	}

	solve(root->left , sum);

	*sum += root->data;

	root->data = *sum;

	solve(root->right , sum);
}

void final(Node *root)
{
	int sum = 0;

	solve(root , &sum);
}

int main()
{
    /* Create following BST
            9
            / \
        6     15 */
    Node* root = newNode(9);
    root->left = newNode(6);
    root->right = newNode(15);
  
    printf(" Original BST\n");
    inorder(root);
  
    final(root);
  
    printf("\n BST To Binary Tree\n");
    inorder(root);
  
    return 0;
}
