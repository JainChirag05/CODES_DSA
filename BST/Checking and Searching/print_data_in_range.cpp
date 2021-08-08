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

void solve(Node *root , int min , int max)
{
	if(root == NULL)
	{
		return;
	}

	if(root->data > min)
	{
		solve(root->left , min , max);
	}

	if(root->data >= min && root->data <= max)
	{
		cout << root->data << " ";
	}

	if(root->data < max)
	{
		solve(root->right , min , max);
	}
}

int main()
{
    Node *root = NULL;
    int k1 = 10, k2 = 25;
     
    /* Constructing tree given
    in the above figure */
    root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
     
    solve(root, k1, k2);
    return 0;
}