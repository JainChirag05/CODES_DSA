#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n)
{
	if(n == 1)
	{
		return 0;
	}

	int jumps[n];
	jumps[0] = 0;

	for(int i = 1; i< n;i++)
	{
		jumps[i] = INT_MAX;
	}


	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(dp[j] != INT_MAX && i <= j + arr[j])
			{
				jumps[i] = min(jumps[i] , jumps[j] + 1);

			}
		}
	}	

	return jumps[n-1];
}

int better(int arr[] , int n)
{
	if(n == 1)
	{
		return 0;
	}

	int jump = 1;
	int max_end = arr[0];
	int step = arr[0];

	for(int i = 1;i<n-1;i++)
	{
		max_end = max(max_end , i + arr[i]);
		step--;

		if(step < 0)
		{
			return -1;
		}

		if(step == 0)
		{
			jump++;
			step = max_end - i;
		}
	}

	if(max_end >= n-1)
	{
		return jump;
	}

	return -1;
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

	cout << solve(arr , n);	
}