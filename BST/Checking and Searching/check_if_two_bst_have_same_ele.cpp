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

void insert_set(Node *root , unordered_set<int> s)
{
	if(root == NULL)
	{
		return;
	}

	insert_set(root->left , s);
	s.insert(root->data);
	insert_set(root->right , s);
}

bool final(Node *n1 , Node *n2)
{
	if(n1 == NULL && n2 == NULL)
	{
		return true;
	}

	if(n1 == NULL || n2 == NULL)
	{
		return false;
	}

	unordered_set <int> s1 , s2;

	insert_set(n1,s1);
	insert_set(n2,s2);

	return (s1 == s2);
}

int main()
{
    // First BST
    Node* root1 = newNode(15);
    root1->left = newNode(10);
    root1->right = newNode(20);
    root1->left->left = newNode(5);
    root1->left->right = newNode(12);
    root1->right->right = newNode(25);
     
    // Second BST
    Node* root2 = newNode(15);
    root2->left = newNode(12);
    root2->right = newNode(20);
    root2->left->left = newNode(5);
    root2->left->left->right = newNode(10);
    root2->right->right = newNode(25);
     
    // check if two BSTs have same set of elements
    if (final(root1, root2))
        cout << "YES";
    else
        cout << "NO";
    return 0;       
}