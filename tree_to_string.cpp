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

void convert(Node *root , string& str)
{
	if(root == NULL)
	{
		return;
	}

	str.push_back(root->data + '0');

	if(root->left == NULL && root->right == NULL)
	{
		return;
	}

	str.push_back('(');
	convert(root->left , str);
	str.push_back(')');

	if(root->right != NULL)
	{
		str.push_back('(');
		convert(root->right , str);
		str.push_back(')');
	}
}


int main()
{
    /* Let us construct below tree
                1
               / \
              2   3
             / \   \
            4   5   6    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    string str = "";

    convert(root, str);

    cout << str;
}