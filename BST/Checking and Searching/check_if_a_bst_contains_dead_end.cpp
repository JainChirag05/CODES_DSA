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

//Dead End -- Can't insert any element after it

//traverse till min = max


bool solve(Node *root , int min = 1 , int max = INT_MAX)
{
	if(root == NULL)
	{
		return false;
	}

	if(min == max)
	{
		return true;
	}

	return solve(root->left , min , root->data-1) || solve(root->right , root->data+1 , max);
}

int main()
{
    /*   8
       /   \
      5    11
     /  \
    2    7
     \
      3
       \
        4 */
    Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    if (solve(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}