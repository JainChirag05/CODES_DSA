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

//Find LCA then add distance between (a and lca) and (b and lca)

int root_dist(Node *root , int x) //dist between root and a node and x
{
	if(root->data == x)
	{
		return 0;
	}

	else if(root->data > x)
	{
		return 1 + root_dist(root->left , x);
	}

	return 1 + root_dist(root->right , x);
}

int find(Node *root , int a , int b) //Assuming b > a and both are present
{
	if(root == NULL)
	{
		return 0;
	}

	if(root->data > a && root->data > b)
	{
		return find(root->left , a , b);
	}

	if(root->data < a && root->data < b)
	{
		return find(root->right , a , b);
	}

	if(root->data >= a && root->data <= b)
	{
		return root_dist(root , a) + root_dist(root , b);
	}

	return 1;
}

int final(Node *root , int a , int b)
{
	if(a > b)
	{
		swap(a,b);
	}

	return find(root , a , b);
}

int main()
{
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);
    int a = 5, b = 55;
    cout << final(root, 5, 35);
    return 0;
}

