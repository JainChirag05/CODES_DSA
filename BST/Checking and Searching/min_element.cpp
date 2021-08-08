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

Node *insert(Node *root , int val)
{
	if(root == NULL)
	{
		return newNode(val);
	}

	if(root->data > val)
	{
		root->left = insert(root->left , val);
	}

	else
	{
		root->right = insert(root->right , val);
	}

	return root;
}

int min_ele(Node *root)
{
	if(root == NULL)
	{
		return -1;	
	}

	Node *curr = root;

	while(curr->left != NULL)
	{
		curr = curr->left;
	}

	return curr->data;
}

int main() 
{ 
	Node* root = NULL; 
	root = insert(root, 4); 
	insert(root, 2); 
	insert(root, 1); 
	insert(root, 3); 
	insert(root, 6); 
	insert(root, 5); 
  
	cout << "Minimum value in BST is " << min_ele(root); 
 
	return 0; 
} 