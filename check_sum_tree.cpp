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

//Naive has O(n^2) complexity

bool leaf(Node *root)
{
	return (root->left == NULL && root->right == NULL);
}

int sum(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	return sum(root->left) + root->data + sum(root->right);
}

bool naive(Node* root,int *sum)
{
    if(root==NULL)
    {
        *sum=0;
        return true;
    }
        
    if(leaf(root)==true)
    {
        *sum=root->data;
        return true;
    }
    
    int ls=0,rs=0;
        
    bool lst = naive(root->left , &ls);
    bool rst = naive(root->right , &rs);
    
    *sum=ls+rs+root->data;

    return (root->data==ls+rs) && lst && rst;
}

bool naive_final(Node *root)
{
	int sum = 0;

	return naive(root , &sum);
}

bool optimal(Node *root)
{
	int l = 0;
	int r = 0;

	if(root == NULL || leaf(root))
	{
		return true;
	}

	if(optimal(root->left) && optimal(root->right))
	{
		if(root->left == NULL)
		{
			l = 0;
		}

		else if(leaf(root->left))
		{
			l = root->left->data;
		}

		else
		{
			l = 2 * (root->left->data);
		}

		if(root->right == NULL)
		{
			r = 0;
		}

		else if(leaf(root->right))
		{
			r = root->right->data;
		}

		else
		{
			r = 2 * (root->right->data);
		}

		return (root->data == r+l);
	}

	return false;
}

int main()
{
    Node *root  = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    if(optimal(root))
        cout << "The given tree is a SumTree " << endl;
    else
        cout << "The given tree is not a SumTree " << endl;

    if(naive_final(root))
        cout << "The given tree is a SumTree " << endl;
    else
        cout << "The given tree is not a SumTree " << endl;
    return 0;
}