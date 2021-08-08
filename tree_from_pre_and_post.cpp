#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int num)
{
	Node *temp = new Node();
	temp->data = num;
	temp->left = temp->right = NULL;

	return temp;
}

Node *build(int preorder[] , int postorder[] ,int *idx, int st , int end , int size)
{
	if(st > end || *idx > size)
	{
		return NULL;
	}

	Node *temp = newNode(preorder[*idx]);
	++*idx;

	if(st == end)
	{
		return temp;
	}

	int i;

	for(i = st;i<=end;i++)
	{
		if(preorder[*idx] == postorder[i])
		{
			break;
		}
	}

	if(i <= end)
	{
		temp->left = build(preorder , postorder ,idx ,st , i , size);
		temp->right = build(preorder,postorder, idx , i+1,end , size);
	}

	return temp;

}

Node *final(int preorder[] , int postorder[] , int size)
{
	int idx=0;
	return build(preorder , postorder , &idx , 0 , size-1 , size);
}

void printi(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	printi(root->left);
	cout << root->data << " ";
	printi(root->right);
}


int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    Node *root = final(pre, post,size);
 
    cout<<"Inorder traversal of the constructed tree: \n";
    printi(root);
 
    return 0;
}