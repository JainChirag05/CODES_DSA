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

void preOrder(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);

}

Node *solve(string s , int &i)
{
	if(i >= s.length())
	{
		return NULL;
	}

	string num = "";

	while(i < s.length() && s[i] != '(' && s[i] != ')')
	{
		num += s[i];
		i++;
	}

	Node *root = newNode(stoi(num));

	if(i < s.length() && s[i] == '(')
	{
		i++;

		root->left = solve(s , i);

		i++;

		if(i < s.length() && s[i] == '(')
		{
			i++;

			root->right = solve(s , i);

			i++;
		}
	}

	return root;
}

Node *final(string s)
{
	int i = 0;
	Node *root = solve(s , i);

	return root;
}

int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node* root = final(str);
    preOrder(root);
}
