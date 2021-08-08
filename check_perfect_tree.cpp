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

//num of nodes in perfect tree are 2^(h)-1;

int height(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	return 1 + max(height(root->left) , height(root->right));
}

int nodes(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	return nodes(root->left) + 1 + nodes(root->right);
}

bool check(Node *root)
{
	int h = height(root);
	int num = nodes(root);

	if(num +1 == pow(2 , h))
	{
		return true;
	}

	else
	{
		return false;
	}
}

int main()
{
    Node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
  
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);
  
    if (check(root))
        printf("Yes\n");
    else
        printf("No\n");
  
    return(0);
}