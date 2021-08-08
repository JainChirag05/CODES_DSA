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

int convert(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int old = root->data;

	root->data = convert(root->left) + convert(root->right);

	return old + root->data;
}

int main() 
{ 
    Node *root = NULL; 
    //int x; 
      
    /* Constructing tree given in the above figure */
    root = newNode(10); 
    root->left = newNode(-2); 
    root->right = newNode(6); 
    root->left->left = newNode(8); 
    root->left->right = newNode(-4); 
    root->right->left = newNode(7); 
    root->right->right = newNode(5); 
      
    convert(root); 
      
    // Print inorder traversal of the converted
    // tree to test result of toSumTree() 
    cout<<"Inorder Traversal of the resultant tree is: \n";

    inorder(root); 
    
    return 0; 
} 