#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *getNode(int val)
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

Node *lca(Node *root , int n1 , int n2)
{
	if(root == NULL)
	{
		return NULL;
	}

	if(root->data == n1 || root->data == n2)
	{
		return root;
	}

	Node *l = lca(root->left , n1 , n2);
	Node *r = lca(root->right , n1 , n2);

	if(l!= NULL && r!=NULL)
	{
		return root;
	}

	else
	{
		if(l && r== NULL)
		{
			return l;
		}

		else
		{
			return r;
		}
	}
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

void ans(Node *root , int n1 , int n2)
{
	Node *n = lca(root , n1 , n2);

	int x = n->data;

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
    struct Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->right->left = getNode(8);
    root->right->left->right = getNode(9);
         
    int n1 = 4, n2 = 8;
    ans(root, n1, n2);
    return 0;
}
