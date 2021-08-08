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

void solve(Node *root , int min , int max ,int &count)
{
	if(root == NULL)
	{
		return;
	}

	if(root->data > min)
	{
		solve(root->left , min , max , count);
	}

	if(root->data >= min && root->data <= max)
	{
		count++;
	}

	if(root->data < max)
	{
		solve(root->right , min , max ,count);
	}
}

int final(Node *root , int min , int max)
{
	int count = 0;

	solve(root , min , max , count);

	return count;
}

int main()
{
    // Let us construct the BST shown in the above figure
    Node *root        = newNode(10);
    root->left        = newNode(5);
    root->right       = newNode(50);
    root->left->left  = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    /* Let us constructed BST shown in above example
          10
        /    \
      5       50
     /       /  \
    1       40   100   */
    int l = 5;
    int h = 45;

    cout << "Count of nodes between [" << l << ", " << h
         << "] is " << final(root , l , h);
    return 0;
}