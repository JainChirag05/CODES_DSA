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

Node *naive(int pre[] , int n , int *ind , int st , int end)
{
	//O(n^2)


	if(*ind >= n || st > end)
	{
		return NULL;
	} 

	Node *root = newNode(pre[*ind]);
	*ind = *ind + 1;

	if(st == end)
	{
		return root;
	}

	int i;

	for(i = st;i<=end;i++)
	{
		if(pre[i] > root->data)
		{
			break;
		}
	}

	root->left = naive(pre , n , ind , *ind , i-1);
	root->right = naive(pre , n  , ind , i , end);

	return root;
}

Node *naive_final(int pre[] , int n)
{
	int ind = 0;

	return naive(pre , n , &ind , 0 , n-1);
}

Node *better(int pre[] , int n , int *ind , int min , int max , int key)
{
	if(*ind >= n)
	{
		return NULL;
	}

	Node *root = NULL;

	if(key > min && key < max)
	{
		root = newNode(key);
		*ind = *ind + 1;

		if(*ind < n)
		{
			root->left = better(pre , n , ind , min , key , pre[*ind]);
		}

		if(*ind < n)
		{
			root->right = better(pre , n , ind , key , max , pre[*ind]);
		}
	}

	return root;
}

Node *better_final(int pre[] , int n)
{
	int ind = 0;

	return better(pre ,n , &ind , INT_MIN , INT_MAX , pre[0]);
}

int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 
    Node* root = better_final(pre, size);
 
    cout << "Inorder traversal of the constructed tree: \n";
    inorder(root);


 
    return 0;
}
