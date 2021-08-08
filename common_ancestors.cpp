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

Node *lca(Node *root , int n1 , int n2)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(root->data == n1 || root->data == n2)
	{
		return root;
	}

	Node *l = lca(root->left , n1 , n2);
	Node *r = lca(root->right , n1 , n2);

	if(l!= NULL && r != NULL)
	{
		return root;
	}

	else
	{
		if(l != NULL && r == NULL)
		{
			return l;
		}

		else
		{
			return r;
		}
	}
}

bool common (Node *root , int n)
{
	if(root == NULL)
	{
		return false;
	}

	if(root->data == n)
	{
		cout << root->data << " ";
		return true;
	}

	if(common(root->left , n) || common(root->right , n))
	{
		cout << root->data << " ";
		return true;
	}

	return false;
}

bool final(Node *root , int n1 , int n2)
{
	Node *temp = lca(root , n1 , n2);

	if(temp == NULL)
	{
		return false;
	}

	common(root , temp->data);

	return true;
}

int main()
{
    // Let us create binary tree given in the above
    // example
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(10);
  
    if (final(root, 9, 7) == false)
        cout << "No Common nodes";
  
    return 0;
}