#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n)
{
	int max_far = arr[0];
	int max_end = arr[0];
	int dp[n+1];

	for(int i = 1;i<n;i++)
	{
		max_end = max(arr[i] , max_end + arr[i]);
		max_far = max(max_end , max_far);
	}

	return max_far;
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

	cout << solve(arr , n) << endl;
	
}