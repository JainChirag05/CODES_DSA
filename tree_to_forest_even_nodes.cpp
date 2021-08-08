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
	temp->data = val;

	temp->left = temp->right = NULL;
}

//TBD after DFS


int main()
{
	
}