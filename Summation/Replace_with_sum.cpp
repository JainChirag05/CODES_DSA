#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *getNode(int num)
{
	Node *temp = new Node();
	temp->data = num;
	temp->left = temp->right = NULL;
	
	return temp;
}

void storeinorder(Node *root , vector<int>& arr)
{
	if(root == NULL)
	{
		return;
	}
	
	storeinorder(root->left , arr);
	arr.push_back(root->data);
	storeinorder(root->right , arr);
}

void replace(Node *root , vector<int> arr , int *i)
{
	if(root == NULL)
	{
		return;
	}
	
	replace(root->left , arr , i);
	
	root->data = arr[*i-1] + arr[*i+1];
	
	++*i;
	
	replace(root->right , arr, i);
}

void final(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	vector<int> arr;
	
	arr.push_back(0);
	
	storeinorder(root, arr);
	
	arr.push_back(0);
	
	int i = 1;
	
	replace(root , arr , &i);
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

int main()
{
    // binary tree formation
    Node* root = getNode(1); /*         	   1        */
    root->left = getNode(2);        /*       /   \      */
    root->right = getNode(3);       /*     2      3     */
    root->left->left = getNode(4);  /*    /  \  /   \   */
    root->left->right = getNode(5); /*   4   5  6   7   */
    root->right->left = getNode(6);
    root->right->right = getNode(7);
  
    cout << "Preorder Traversal before tree modification: ";
    preorder(root);
  
    final(root);
  
    cout << "\nPreorder Traversal after tree modification: ";
    preorder(root);
  
    return 0;
}
	
	
	
	

	
	
	
