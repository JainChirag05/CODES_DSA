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

bool check(Node *n1 , Node *n2)
{
	if(n1 == NULL && n2 == NULL)
	{
		return true;
	}

	if(n1 == NULL || n2 == NULL)
	{
		return false;
	}

	return ((n1->data == n2->data) && check(n1->left , n2->right) && check(n1->right , n2->left));
}

int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);
 
    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);
 
    check(a, b)? cout << "Yes" : cout << "No";
 
    return 0;
}