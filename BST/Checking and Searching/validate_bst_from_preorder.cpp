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

bool check(int pre[] , int n)
{
	stack <int> st;

	int root = INT_MIN;

	for(int i = 0;i<n;i++)
	{
		while(!st.empty() && pre[i] > st.top())
		{
			root = st.top();
			st.pop();
		}

		if(pre[i] < root)
		{
			return false;
		}

		st.push(pre[i]);
	}

	return true;
}

int main()
{
    int pre[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre)/sizeof(pre[0]);
   	check(pre, n)? cout << "true\n":cout << "false\n";
}