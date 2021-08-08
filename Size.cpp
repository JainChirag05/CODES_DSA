#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	
	Node *left;
	Node *right;
};

Node *newNode(int num)
{
	Node *temp = new Node();
	
	temp->data = num;
	temp->left = temp->right = NULL;
	
	return temp;
}

int size(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	else
	{
		return (size(root->left) + 1 + size(root->right));
	}
}

int main() 
{ 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
      
    cout << "Size of the tree is " << size(root); 
    return 0; 
} 
