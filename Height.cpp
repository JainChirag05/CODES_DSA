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
	temp->left = temp->right = NULL;
	
	return temp;
}

int height(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	else
	{
	
		int l = height(root->left);
		int r = height(root->right);
	
		return max(l+1 , r+1);
	}
}

int main()
{
    Node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);
     
    cout << height(root) << endl;
    return 0;
}

