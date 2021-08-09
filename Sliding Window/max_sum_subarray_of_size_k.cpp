#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int k)
{
	int sum = 0;
	int max_sum = 0;

	for(int i = 0;i<k;i++)
	{
		sum += arr[i];
	}

	max_sum = sum;

	for(int i = k;i<n;i++)
	{
		sum += arr[i] - arr[i-k];

		max_sum = max(max_sum , sum);
	}

	return max_sum;
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

	int k;
	cin >> k;


	cout << solve(arr , n , k);
	
}