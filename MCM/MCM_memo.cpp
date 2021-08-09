#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int t[1001][1001];

int solve(int arr[] , int i , int j)
{
	int ans = INT_MAX;

	if(i >= j)
	{
		t[i][j] = 0;
		return 0;
	}

	for(int k = i;k<j;k++)
	{
		int temp = solve(arr , i , k) + solve(arr , k+1 , j) + (arr[i-1]*arr[k]*arr[j]);

		ans = min(temp , ans);
	}

	return t[i][j] = ans;
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

	memset(t , -1 , sizeof(t));

	cout <<solve(arr , 1 , n-1);
	
}