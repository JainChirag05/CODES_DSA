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

vector <int> merge(vector<int> v1 , vector<int> v2)
{
	int m = v1.size();
	int n = v2.size();

	vector <int> final;
	int i = 0 , j = 0;	

	while(i < m && j < n)
	{
		if(v1[i] < v2[j])
		{
			final.push_back(v1[i]);
			i++;
		}

		else
		{
			final.push_back(v2[j]);
			j++;
		}
	}

	while(i < m)
	{
		final.push_back(v1[i]);
		i++;
	}

	while(j < n)
	{
		final.push_back(v2[j]);
		j++;
	}

	return final;
}

Node *build(vector <int> res , int st , int end)
{
	if(st > end)
	{
		return NULL;
	}

	int mid = (st+end)/2;

	Node *root = newNode(res[mid]);

	root->left = build(res , st , mid-1);
	root->right = build(res , mid+1 , end);

	return root;
}

Node *final(Node *root1 , Node *root2)
{
	vector <int> v1;
	vector <int> v2;

	store_inorder(root1 , v1);
	store_inorder(root2 , v2);

	vector <int> final = merge(v1 , v2);

	int x = final.size();

	Node *node = build(final, 0 , x-1);

	return node;
}

//if in place use DLL

int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    Node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
 
    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    Node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);
 
    Node *mergedTree = final(root1, root2);
 
    cout << "Following is Inorder traversal of the merged tree \n";
    inorder(mergedTree);
 
    return 0;
}

