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

Node* insert(Node* node, int val)
{
    if (node == NULL)
    {
    	return newNode(val);
    }    
 
    if (val < node->data)
    {
		node->left = insert(node->left, val);
    }

    else if (val > node->data)
    {
    	node->right = insert(node->right, val);
    }    
 
    return node;
}

bool isleaf(Node *root)
{
	if(root->left == NULL && root->right == NULL)
	{
		return true;
	}

	return false;
}

Node *solve(Node *root)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(isleaf(root))
	{
		delete (root);
		return NULL;
	}

	root->left = solve(root->left);
	root->right = solve(root->right);

	return root;
}

int main()
{
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);
    cout << "Inorder before Deleting the leaf Node." << endl;
    inorder(root);
    cout << endl;
    solve(root);
    cout << "INorder after Deleting the leaf Node." << endl;
    inorder(root);
    return 0;
}