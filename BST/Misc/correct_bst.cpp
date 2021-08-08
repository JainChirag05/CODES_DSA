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

Node* insert(Node* node, int val)
{
    if (node == NULL)
    {
    	return newNode(val);
    }    
 
    if (val < node->data)
    {
		node->left = insert(node->left, val);
    }

    else if (val > node->data)
    {
    	node->right = insert(node->right, val);
    }    
 
    return node;
}

void swap(int *a , int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void calc(Node *root , Node **first , Node **mid , Node **last , Node **prev)
{
	if(root == NULL)
	{
		return;
	}

	calc(root->left , first , mid , last , prev);

	if(*prev && root->data < (*prev)->data)
	{
		if(!*first)
		{
			*first = *prev;
			*mid = root;
		}

		else
		{
			*last = root;
		}

	}

	*prev = root;

	calc(root->right , first , mid , last , prev);
}

void restore(Node *root)
{
	Node *first = NULL , *mid = NULL , *last = NULL , *prev = NULL;

	calc(root , &first , &mid , &last , &prev);

	if(first && last)
	{
		swap(&(first->data) , &(last->data));
	}

	else if(first && mid)
	{
		swap(&(first->data) , &(mid->data));
	}
}

int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    Node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
 
    cout <<"Inorder Traversal of the original tree \n";
    inorder(root);
 
    restore(root);
 
    cout <<"\nInorder Traversal of the fixed tree \n";
    inorder(root);
 
    return 0;
}