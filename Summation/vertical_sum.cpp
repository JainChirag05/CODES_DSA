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

void solve(Node *root , int d , map <int,int> &mp)
{
	if(root == NULL)
	{
		return;
	}

	solve(root->left , d-1, mp);
	mp[d] += root->data;
	solve(root->right , d+1 , mp);
}

void final(Node *root)
{
	map <int,int> mp;	

	solve(root , 0 , mp);

	for(auto it = mp.begin(); it != mp.end();++it)
	{
		cout << it->second << " ";
	}

}

int main()
{
    // Create binary tree as shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
  
    final(root);
  
    return 0;
}