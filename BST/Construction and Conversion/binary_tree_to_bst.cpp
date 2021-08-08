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

void store_inorder(Node *root , vector <int> &res)
{
	if(root == NULL)
	{
		return;
	}

	store_inorder(root->left ,res);
	res.push_back(root->data);
	store_inorder(root->right , res);
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

void convert(Node *root , vector<int> res  ,int &ind)
{
	if(root == NULL)
	{
		return;
	}

	convert(root->left , res , ind);
	root->data = res[ind++];
	convert(root->right , res , ind);
}

Node *final(Node *root)
{
	vector <int> res;

	store_inorder(root , res);

	sort(res.begin() , res.end());

	int ind = 0;

	convert(root , res , ind);

	return root;
}

int main()
{
    Node* root = NULL;
 
    /* Constructing tree given in the above figure
        10
        / \
        30 15
    /     \
    20     5 */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 
    // convert Binary Tree to BST
    final(root);
 
    printf("Following is Inorder Traversal of the converted BST: \n");
    inorder(root);
 
    return 0;
}

