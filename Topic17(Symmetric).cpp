#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left = NULL;
	Node *right = NULL;
};

Node *newNode(int num)
{
	Node *temp = new Node();
	temp->left = temp->right = NULL;
}

bool mirror(Node *n1 , Node *n2)
{
	if(n1 == NULL && n2 == NULL)
	{
		return true;
	}
	
	if(n1 && n2 && n1->data == n2->data)
	{
		return mirror(n1->left,n2->right) && mirror(n1->right , n2->left);
	}
	
	return false;
}

bool issym(Node *root)
{
	return mirror(root , root);
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
 
    if(issym(root))
      cout<<"Symmetric";
    else
      cout<<"Not symmetric";
    return 0;
}
