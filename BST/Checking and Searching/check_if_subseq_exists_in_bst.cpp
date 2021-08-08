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

void check(Node *root , int seq[] , int &idx)
{
	if(root == NULL)
	{
		return;
	}

	check(root->left , seq , idx);

	if(root->data == seq[idx])
	{
		idx++;
	}

	check(root->right , seq , idx);
}

bool final(Node *root , int seq[] , int n)
{
	int idx = 0;

	check(root , seq , idx);

	if(idx == n)
	{
		return true;
	}

	return false;
}

int main()
{
    Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);
  
    int seq[] = {4, 6, 8, 14};
    int n = sizeof(seq)/sizeof(seq[0]);
  
    final(root, seq, n)? cout << "Yes" :
                            cout << "No";
  
    return 0;
}