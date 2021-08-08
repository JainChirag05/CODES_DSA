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

	if(root->left == NULL && root->right == NULL)
	{
		return root->data;
	}

	int left = convert(root->left);
	int right = convert(root->right);

	root->data += left;


	return root->data + right;
}

int main() 
{ 
    /* Let us construct below tree 
                1 
            / \ 
            2 3 
            / \ \ 
            4 5 6 */
    Node *root = newNode(1); 
    root->left     = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
  
    convertnewNode(root); 
  
    cout << "Inorder traversal of the modified tree is: \n"; 
    inorder(root); 
    return 0; 
} 