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

bool check(Node *root , unordered_set <int> &s)
{
	if(root == NULL)
	{
		return false;
	}

	if(s.find(root->data) != s.end())
	{
		return true;
	}

	s.insert(root->data);

	return ((check(root->left , s)) || check(root->right , s));
}

int main()
{
	unordered_set <int> s;

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    if (check(root , s))
        printf("Yes");
    else
        printf("No");
  
    return 0;
}