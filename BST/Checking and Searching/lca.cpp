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

Node *lca_iter(Node *root , int n1 , int n2)
{
	while(root)
	{
		if(root->data > n1 && root->data > n2)
		{
			root = root->left;
		}

		else if(root->data < n1 && root->data < n2)
		{
			root = root->right;
		}

		else
		{
			break;
		}
	}

	return root;
}

int main() 
{ 
    // Let us construct the BST 
    // shown in the above figure 
    Node *root = newNode(20); 
    root->left = newNode(8); 
    root->right = newNode(22); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
  
    int n1 = 10, n2 = 14; 
    Node *t = lca(root, n1, n2); 
    Node *trec = lca_iter(root, n1, n2); 
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl; 
    cout << "LCA of " << n1 << " and " << n2 << " is " << trec->data<<endl; 

  
    n1 = 14, n2 = 8; 
    t = lca(root, n1, n2);
    trec = lca_iter(root, n1, n2); 
    cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl; 
    cout << "LCA of " << n1 << " and " << n2 << " is " << trec->data<<endl;
  
    n1 = 10, n2 = 22; 
    t = lca(root, n1, n2);
    trec = lca_iter(root, n1, n2); 
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl; 
    cout << "LCA of " << n1 << " and " << n2 << " is " << trec->data<<endl;
    return 0; 
} 