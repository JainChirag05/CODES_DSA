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

bool check(Node *root)
{
	int left = 0;
	int right = 0;

	if(root == NULL || (root->left == NULL && root->right == NULL))
	{
		return true;
	}

	else
	{
		if(root->left != NULL)
		{
			left = root->left->data;
		}

		if(root->right != NULL)
		{
			right = root->right->data;
		}

		if(root->data == left + right && check(root->left) && check(root->right))
		{
			return true;
		}

		else
		{
			return false;
		}
	}

}

int main()
{
    Node *root = newNode(10);
    root->left     = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(2);
    if((root))
        cout << "The given tree satisfies "
            << "the children sum property ";
    else
        cout << "The given tree does not satisfy "
            << "the children sum property ";
  
    getchar();
    return 0;
}