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

Node *search(Node *root , int val)
{
	if(root->data == val)
	{
		return root;
	}

	if(root->data < val)
	{
		return search(root->right , val);
	}

	else
	{
		return search(root->left , val);
	}
}

bool check(Node *root , int min , int max)
{
	if(root == NULL)
	{
		return true;
	}

	if(root->data > max || root->data < min)
	{
		return false;
	}

	else
	{
		return check(root->left , min , root->data-1) && check(root->right , root->data+1 , max);  //to void duplicacy
	}

	return false;
}

bool final(Node *root)
{
	int min = INT_MIN;
	int max = INT_MAX;

	return check(root , min , max);
}

bool check2(Node *root , Node *l = NULL , Node *r = NULL)
{
	if(root == NULL)
	{
		return true;
	}

	if(l != NULL && root->data <= l->data)
	{
		return false;
	}

	if(r != NULL && root->data >= r->data)
	{
		return false;
	}

	else
	{
		return check2(root->left , l , root) && check2(root->right , root , r);
	}
}

int main()
{
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
     
    if(final(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";

    cout << endl;

    if(check2(root , NULL , NULL))
        cout<<"Is BST";
    else
        cout<<"Not a BST";
         
    return 0;
}