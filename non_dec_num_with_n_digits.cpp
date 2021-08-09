#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int n)
{
	int dp[10][n+1];
	memset(dp , 0 , sizeof(dp));

	for(int i = 0;i<10;i++)
	{
		dp[i][1] = 1;
	}

	for(int i = 0 ;i<=9;i++)
	{
		for(int j = 2 ; j<=n;j++)
		{
			for(int k = 0;k<=i;k++)
			{
				dp[i][j] += dp[k][j-1];
			}
		}
	}

	int count = 0;

	for(int i = 0;i<10;i++)
	{
		count += dp[i][n];
	}

	return count;
}

int main()
{
	int n;
	cin >> n;

	cout << solve(n);
	
}