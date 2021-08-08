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

void convert(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	convert(root->left);
	convert(root->right);

	if(!root->left)
	{
		root->left = root->right;
	}

	else
	{
		root->left->right = root->right;
	}

	root->right = NULL;
}
void traversal(Node *root)
{
	if(root== NULL)
	{
		return;
	}

	cout << root->data << " ";
	traversal(root->right);
	traversal(root->left);
}

int main()
{
    // Let us create binary tree shown in above diagram
    /*
           1
         /   \
        2     3
             / \
            4   5
           /   /  \
          6   7    8
    */
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);
  
    convert(root);
  
    cout << "Traversal of the tree converted to down-right form\n";
    traversal(root);
  
    return 0;
}