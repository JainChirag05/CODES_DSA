#include <bits/stdc++.h>

using namespace std;

struct Node
{
	char data;
	Node *left;
	Node *right;
};

Node *newNode(char num)
{
	Node *temp = new Node();
	
	temp->left = temp->right = NULL;
	
	temp->data = num;
	
	return temp;	
}

void solve(Node *n1 , Node *n2 , int l)
{
	if(n1 == NULL || n2 == NULL)
	{
		return;
	}
	
	if(l%2 == 0)
	{
		swap(n1->data , n2->data);
	}
	
	solve(n1->left , n2->right , l+1);
	solve(n1->right , n2->left , l+1);
}


void final(Node *root)
{
	solve(root->left , root->right , 0);
}

void print(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	print(root->left);
	cout << root->data << " ";
	print(root->right);
}

int main()
{
    Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');
  
    cout << "Inorder Traversal of given tree\n";
    print(root);
  
    final(root);
  
    cout << "\n\nInorder Traversal of modified tree\n";
    print(root);
    return 0;
}
	
	
