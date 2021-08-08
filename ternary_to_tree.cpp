#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node
{
	char data;
	Node *left;
	Node *right;
};

Node *newNode(char val)
{
	Node *temp = new Node();
	temp->data = val;
	temp->left = temp->right = NULL;

	return temp;
}

Node *convert(string s , int i)
{
	int n = s.length();

	if(i == n)
	{
		return NULL;
	}

	Node *root = newNode(s[i]);

	if(i == n-1)
	{
		return root;
	}

	if(i+1 < n && s[i+1] == '?')
	{
		root->left = convert(s , i+2);
	}

	if(i+1 < n && s[i+1] == ':')
	{
		root->right = convert(s , i+2);
	}

	return root;
}

void print(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

int main()
{
    string s;
    cin >> s;
    Node *root = convert(s, 0);
    print(root);
    return 0;
}