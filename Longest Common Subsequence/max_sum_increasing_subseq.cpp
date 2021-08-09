#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int a[] , int n)
{
	int dp[n];

	for(int i = 0;i<n;i++)
	{
		dp[i] = a[i];
	}

	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(a[i] > a[j])
			{
				dp[i] = max(a[i] + dp[j] , dp[i]);
			}
		}
	}

	int ans = INT_MIN;

	for(int i = 0;i<n;i++)
	{
		ans = max(ans , dp[i]);
	}

	return ans;
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