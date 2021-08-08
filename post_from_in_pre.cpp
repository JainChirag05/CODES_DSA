#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;

};


Node* createnode(int num)
{
	Node *temp = new Node();
	temp->data = num;
	temp->left = temp->right = NULL;

	return temp;
}
//Naive way -- Create tree and print postorder
//O(n^2) for linear search.....map for O(n)

//Better way -- 1st element of pre is root and last element of post is root
//Elements before root in inorder are left subtree and rest are right subtree

int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        return i;
    }
    return -1;
}

void naive(int in[], int pre[], int n)
{
    int root=search(in,pre[0],n) ;

    // If left subtree is not empty, print left subtree 
    if (root != 0)
    {
        naive(in, pre + 1, root);
    }

    // If right subtree is not empty, print right subtree   
    if (root != n - 1)
    {
        naive(in + root + 1, pre + root + 1, n - root - 1);
    }

	// Print root
    cout << pre[0] << " ";
}

int idx = 0;

void solve(int in[] , int pre[] , int st , int end ,  unordered_map<int,int> mp)
{
	if(st > end)
	{
		return;
	}

	int ind = mp[pre[idx++]];

	solve(in , pre , st , ind-1 , mp);
	solve(in , pre , ind+1 , end , mp);

	cout << in[ind] << " ";

}

void final(int in[] , int pre[] , int n)
{
	unordered_map<int,int> mp;

	for(int i = 0;i<n;i++)
	{
		mp[in[i]] = i;
	}

	solve(in , pre , 0 , n-1 , mp);
}

int main()
{
    int in[] = {4, 2, 5, 1, 3, 6};
    int pre[] = {1, 2, 4, 5, 3, 6};
    int len = sizeof(in)/sizeof(in[0]);
    
    final(in, pre, len);
}