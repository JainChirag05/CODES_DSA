#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int sum)
{
	int t[n+1][sum+1];

	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=sum;j++)
		{
			if(i == 0)
			{
				t[i][j] = 0;
			}

			if(j == 0)
			{
				t[i][j] = 1;
			}
		}
	}

	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=sum;j++)
		{
			if(j >= arr[i-1])
			{
				int val1 = t[i][j - arr[i-1]];
				int val2 = t[i-1][j];

				t[i][j] = val1 + val2;
			}

			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[n][sum];
}

int better(int arr[] , int n , int sum)
{
	int dp[sum+1];
	memset(dp , 0 , sizeof(dp));

	dp[0] = 1;

	for(int i = 0;i<n;i++)
	{
		for(int j = arr[i];j<=sum;j++)
		{
			dp[j] = dp[j] + dp[j-arr[i]];
		}
	}

	return dp[sum];
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

	int sum;
	cin >> sum;

	cout << solve(arr , n , sum) <<endl;
	cout << better(arr , n , sum) << endl;
	
}