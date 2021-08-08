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

void solve(Node *root , int *sum)
{
	if(root == NULL)
	{
		return;
	}

	solve(root->right , sum);

	*sum += root->data;

	root->data = *sum;

	solve(root->left ,sum);
}

Node *final(Node *root)
{
	int sum = 0;

	solve(root , &sum);

	return root;
}

int main()
{
    /* Let us create following BST
            50
        / \
        30 70
        / \ / \
    20 40 60 80 */
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    final(root);
 
    // print inoder traversal of the modified BST
    inorder(root);
 
    return 0;
}