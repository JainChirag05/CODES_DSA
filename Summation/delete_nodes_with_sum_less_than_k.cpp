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

Node *solve(Node *root , int k , int sum)
{
	if(root == NULL)
	{
		return NULL;
	}

	root->left = solve(root->left , k , sum + root->data);
	root->right = solve(root->right , k , sum + root->data);

	if(root->left == NULL && root->right == NULL)
	{
		if(sum + root->data < k)
		{
			delete(root);
			return NULL;
		}
	}

	return root;	
}

Node *final(Node *root , int k)
{
	int sum = 0;

	return solve(root , k , sum);
}

int main()
{
    int k = 45;
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);
  
    printf("Tree before truncation\n");
    inorder(root);
  
    root = final(root, k); // k is 45
  
    printf("\n\nTree after truncation\n");
    inorder(root);
  
    return 0;
}