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

Node *lca(Node *root , int n1 , int n2)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(root->data > n1 && root->data > n2)
	{
		return lca(root->left , n1 , n2);
	}

	if(root->data < n1 && root->data < n2)
	{
		return lca(root->right , n1 , n2);
	}

	return root;
}

int max_node(Node *root , int x)
{
	if(root == NULL)
	{
		return 0;
	}

	Node *temp = root;

	int maxi = INT_MIN;

	while(temp->data != x)
	{
		if(temp->data > x)
		{
			maxi = max(maxi , temp->data);
			temp = temp->left;
		}

		else
		{
			maxi = max(maxi , temp->data);
			temp = temp->right;
		}
	}

	return max(maxi , x);
}

int final(Node *root , int x , int y)
{
	Node *node = lca(root , x , y);

	return max(max_node(node , x) , max_node(node , y));
}

int main()
{
    int arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 };
    int a = 1, b = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Creating the root of Binary Search Tree
    Node *root = newNode(arr[0]);
 
    // Inserting Nodes in Binary Search Tree
    for (int i = 1; i < n; i++)
        insert(root, arr[i]);
 
    cout << final(root, a, b) << endl;
 
    return 0;
}