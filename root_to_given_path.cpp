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

bool check_path(Node *root , int x , vector <int> &arr)
{
	if(root == NULL)
	{
		return false;
	}

	arr.push_back(root->data);

	if(root->data == x)
	{
		return true;
	}

	if(check_path(root->left , x , arr) || (check_path(root->right , x , arr)))
	{
		return true;
	}

	arr.pop_back();

	return false;
}

void ans(Node *root , int x)
{
	vector<int> res;

	if(check_path(root , x , res))
	{
		for(int i = 0;i<res.size()-1;i++)
		{
			cout << res[i] << "->";
		}

		cout << res[res.size()-1];
	}

	else
	{
		cout << "Nope" << endl;
	}

}

int main()
{
    // binary tree formation
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
          
    int x = 4;
    ans(root, x);
    return 0;
}