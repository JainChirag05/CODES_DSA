//Inorder traversal of expression tree produces infix version of given 
//postfix expression (same with postorder traversal it gives postfix expression)

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	string data;
	Node *left;
	Node *right;
};

Node *newNode(string val)
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

int solve(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	if(root->left == NULL && root->right == NULL)
	{
		return stoi(root->data);
	}

	int l = solve(root->left);
	int r = solve(root->right);

	if(root->data == '+')
	{
		return l + r;
	}

	if(root->data == '-')
	{
		return l-r;
	}

	if(root->data == '*')
	{
		return l*r;
	}

	else
	{
		return l/r;
	}
}

int main() 
{ 
    // create a syntax tree 
    Node *root = newNode("+"); 
    root->left = newNode("*"); 
    root->left->left = newNode("5"); 
    root->left->right = newNode("-4"); 
    root->right = newNode("-"); 
    root->right->left = newNode("100"); 
    root->right->right = newNode("20"); 


    cout << solve(root) << endl;  
} 





