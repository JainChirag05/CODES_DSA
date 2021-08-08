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

//M1 -- Construct tree and then check if it is BST

bool check(int arr[] , int n , int maxi , int mini)
{
	bool flag = true;

	for(int i = 1;i<n;i++)
	{
		// This element can be inserted to the right
        // of the previous element, only if it is greater
        // than the previous element and in the range.

		if(arr[i] > arr[i-1] && arr[i] > mini && arr[i] < maxi)
		{
			mini = arr[i-1];
		}

		// This element can be inserted to the left
        // of the previous element, only if it is lesser
        // than the previous element and in the range.
        
		else if(arr[i] < arr[i-1] && arr[i] > mini && arr[i] < maxi)
		{
			maxi = arr[i-1];
		}

		else
		{
			flag = false;
			break;
		}
	}

	return flag;
}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	if(check(arr , n , INT_MAX , INT_MIN))
	{
		cout << "Yes" << endl;
	}

	else
	{
		cout << "No" << endl;
	}
}