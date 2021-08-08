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
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

bool continous(Node *temp)
{
	if(temp == NULL)
	{
		return true;
	}
	
	if(temp->left == NULL && temp->right == NULL)
	{
		return true;
	}
	
	if(temp->left == NULL)
	{
		return (abs(temp->data - temp->right->data) == 1) && continous(temp->right);
	}
	
	if(temp->right == NULL)
	{
		return (abs(temp->data - temp->left->data) == 1) && continous(temp->left);
	}
	
	return (abs(temp->data - temp->left->data) == 1) && continous(temp->left) && (abs(temp->data - temp->right->data) == 1) && continous(temp->right);
}

int main()
{
    Node *root 		  = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(4);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(5);
    continous(root)?  cout << "Yes" : cout << "No";
    return 0;
}
