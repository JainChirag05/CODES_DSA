#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct List
{
	int val;
	List *next;
};

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(char num)
{
	Node *temp = new Node();
	temp->data = num;
	temp->left = temp->right = NULL;

	return temp;
}


int main()
{
	
}