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

//make tree and find kth level sum

int solve(string s , int k)
{
	int level = -1;
	int sum = 0;
	int n = s.length();

	for(int i = 0;i<n;i++)
	{
		if(s[i] =='(')
		{
			level++;
		}

		else if(s[i] == ')')
		{
			level--;
		}

		else
		{
			if(level == k)
			{
				sum += (s[i] - '0');
			}
		}
	}

	return sum;
}

int main()
{
    string tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
    int k = 2;
    cout << solve(tree, k);
    return 0;
}