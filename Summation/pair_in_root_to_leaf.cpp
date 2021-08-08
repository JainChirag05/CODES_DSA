#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newnode(int val)
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

bool check(Node *node , int data , unordered_set <int> &s)
{
	if(node == NULL)
	{
		return false;
	}

	int diff = data - node->data;

	if(s.find(diff) != s.end())
	{
		return true;
	}

	s.insert(node->data);

	if(check(node->left , data , s) || check(node->right , data , s));
	{
		return true;
	}

	s.erase(node->data);

	return false;
}

bool final(Node *root)
{
	unordered_set <int> s;

	return check(root->left , root->data , s) || check(root->right , root->data , s);
}

int main()
{
    Node *root = newnode(8);
    root->left    = newnode(5);
    root->right   = newnode(4);
    root->left->left = newnode(9);
    root->left->right = newnode(7);
    root->left->right->left = newnode(1);
    root->left->right->right = newnode(12);
    root->left->right->right->right = newnode(2);
    root->right->right = newnode(11);
    root->right->right->left = newnode(3);
    final(root)? cout << "Yes" : cout << "No";
    return 0;
}