#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int coins[] , int n , int sum)
{
	int t[n+1][sum+1];

	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=sum;j++)
		{
			if(j == 0)
			{
				t[i][j] = 0;
			}

			if(i == 0)
			{
				t[i][j] = INT_MAX-1;
			}

			if(i == 1)
			{
				if(j % coins[0] == 0)
				{
					t[i][j] = j/coins[0];
				}

				else
				{
					t[i][j] = INT_MAX-1;
				}
			}
		}
	}

	t[0][0] = 0;

	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=sum;j++)
		{
			if(j >= coins[i-1])
			{
				t[i][j] = min(1 + t[i][j - coins[i-1]] , t[i-1][j]);
			}

			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}

	if(t[n][sum] != INT_MAX-1)
	{
	    return t[n][sum];
	}
	   
	else
	{
	    return -1;
	}
}

int space(int coins[] , int n , int sum)
{
	int dp[sum+1];

	dp[0] = 0;

	for(int i = 1;i<=sum;i++)
	{
		dp[i] = INT_MAX;
	}

	for(int i = 1;i<=sum;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(coins[j] <= i)
			{
				int sub = dp[i - coins[j]];

				if(sub != INT_MAX && sub + 1 < dp[i])
				{
					dp[i] = sub + 1;
				}
			}
		}
	}

	if(dp[sum] != INT_MAX)
	{
		return dp[sum];
	}

	else
	{
		return -1;
	}
}


int main()
{
	int n; 
	cin >> n;

	int coins[n];

	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	int sum; 
	cin >> sum;

	cout << solve(coins, n, sum) << endl;
	cout << space(coins,n,sum);
	
}