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

void solve(Node *root , vector<int> res , int *ind)
{
	if(root == NULL)
	{
		return;
	}

	root->data = res[++*ind];
	solve(root->left , res , ind);
	solve(root->right , res , ind);
}

void final(Node *root)
{
	vector <int> res;
	store_inorder(root , res);

	int ind = -1;
	solve(root , res , &ind);
}

void level(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	queue <Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int n = q.size();

		while(n--)
		{
			Node *temp = q.front();
			q.pop();

			cout << temp->data << " ";

			if(temp->left)
			{
				q.push(temp->left);
			}

			if(temp->right)
			{
				q.push(temp->right);
			}
		}

		cout << endl;
	}
}

int main()
{
    /* Constructing below tree
                8
              /   \
             4     12
           /  \   /  \
          2    6 10   14
     */
 
    Node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
 
    final(root);
 
    /* Output - Min Heap
                2
              /   \
             4     6
           /  \   /  \
          8   10 12   14
     */
 
    level(root);
 
    return 0;
}