#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(pair <int,int> arr[] , int n)
{
	int root = 0;

	for(int i = 0;i<n;i++)
	{
		root += (arr[i].first - arr[i].second);
	}

	return root;
}

int main()
{
    pair<int, int> arr[] = {{1, 5}, {2, 0},
           {3, 0}, {4, 0}, {5, 5}, {6, 5}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", solve(arr, n));
    return 0;
}