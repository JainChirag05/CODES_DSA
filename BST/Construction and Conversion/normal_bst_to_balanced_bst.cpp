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

void preorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
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

void store_inorder(Node *root  ,vector<int> &res)
{
	if(root == NULL)
	{
		return;
	}

	store_inorder(root->left , res);
	res.push_back(root->data);
	store_inorder(root->right , res);
}

Node *build(vector <int> res , int st , int end)
{
	if(st > end)
	{
		return NULL;
	}

	int mid = (st+end)/2;

	Node *root = newNode(res[mid]);

	root->left = build(res , st , mid-1);
	root->right = build(res , mid+1 , end);

	return root;
}

Node *final(Node *root)
{
	vector<int> res;

	store_inorder(root , res);

	int n = res.size();

	Node *node = build(res, 0 , n-1);

	return node;
}

int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
  
    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
  
    root = final(root);
  
    printf("Preorder traversal of balanced "
            "BST is : \n");
    preorder(root);
  
    return 0;
}