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

int solve(Node *root , int val)
{
    if(root == NULL)
    {
        return 0;
    }

    val = (val*10 + root->data);

    if(root->left == NULL && root->right == NULL)
    {
        return val;
    }

    return (solve(root->left , val) + solve(root->right , val));
}

int final(Node *root)
{
    int val = 0;

    return solve(root , val);
}

int main() 
{ 
    Node *root = newNode(6); 
    root->left = newNode(3); 
    root->right = newNode(5); 
    root->left->left = newNode(2); 
    root->left->right = newNode(5); 
    root->right->right = newNode(4); 
    root->left->right->left = newNode(7); 
    root->left->right->right = newNode(4); 
    cout<<"Sum of all paths is "<<final(root); 
    return 0; 
} 
