#include <bits/stdc++.h>

using namespace std;

struct Node 
{
	int data;
	Node *right;
	Node *left;
};

Node *newNode(int num)
{
	Node *temp = new Node();
	
	temp->data = num;
	temp->left = temp->right = NULL;
	
	return temp;
}

void solve_itr(Node *root)
{	
	stack <Node*> s;
	queue <Node*> q;
	
	q.push(root);
	
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		
		s.push(root);
		
		if(root->right != NULL)
		{
			q.push(root->right);
		}
		
		if(root->left != NULL)
		{
			q.push(root->left);
		}	
		
	}
	
	while(!s.empty())
	{
		root = s.top();
		cout << root->data << " ";
		s.pop();
	}
}

//recur method

int height(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}

	int l = height(root->left);
	int r = height(root->right);

	return max(l+1 , r+1);
}

void solve_recur(Node *root , int level)
{
	if(root == NULL)
	{
		return;
	}

	if(level == 1)
	{
		cout << root->data << " ";
	}

	else
	{
		solve_recur(root->left , level-1);
		solve_recur(root->right , level-1);
	}
}

void final_recur(Node *root)
{
	int h = height(root);

	for(int i = h;i>=1;i--)
	{
		solve_recur(root , i);
	}
}
int main()
{
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
  
    cout << "Level Order traversal of binary tree is \n";
    solve_itr(root);
  	cout << endl;
  	final_recur(root);
    return 0;
}
