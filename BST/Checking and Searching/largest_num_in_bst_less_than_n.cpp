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

Node* insert(struct Node* root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int solve(Node *root , int n)
{
	if(root == NULL)
	{
		return -1;
	}

	if(root->data == n)
	{
		return n;
	}

	else if(root->data > n)
	{
		return solve(root->left , n);
	}

	else
	{
		int k = solve(root->right , n);

		if(k == -1)
		{
			return root->data;
		}

		else
		{
			return k;
		}
	}
}

int main()
{
    int N = 4;
 
    // creating following BST
    /*
                  5
               /   \
             2     12
           /  \    /  \
          1   3   9   21
                     /   \ 
                    19   25  */
    Node* root = insert(root, 25);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 21);
    insert(root, 19);
    insert(root, 25);
 
    printf("%d", solve(root, N));
 
    return 0;
}