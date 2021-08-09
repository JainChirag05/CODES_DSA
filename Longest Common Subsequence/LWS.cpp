#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n)
{
	int dp[n][2];

	//dp[n][0] == last ele greater than prev
	//dp[n][1] == last ele smaller then prev

	for(int i = 0;i<n;i++)
	{
		dp[i][0] = dp[i][1] = 1;
	}

	int res = 1;

	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[j] < arr[i])
			{
				dp[i][0] = max(dp[i][0] , dp[j][1] + 1);
			}

			if(arr[j] > arr[i])
			{
				dp[i][1] = max(dp[i][1] , 1 + dp[j][0]);
			}
		}

		res = max(res , max(dp[i][0] , dp[i][1]));
	}

	cout << res;
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

	solve(arr,n);
}