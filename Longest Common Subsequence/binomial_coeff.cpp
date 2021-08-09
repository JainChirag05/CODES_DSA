#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int recur(int n,int k)
{
	if(k > n)
	{
		return -1;
	}

	if(n == k || k == 0)
	{
		return 1;
	}

	return recur(n-1 , k-1) + recur(n-1 , k);
}

int dp[101][101];

int memo(int n , int k)
{
	if(dp[n][k] != -1)
	{
		return dp[n][k];
	}

	if(k == 0 || n == k)
	{
		dp[n][k] = 1;
		return dp[n][k];
	}

	dp[n][k] = memo(n-1,k-1) + memo(n-1 , k);

	return dp[n][k];
}

int top(int n , int k)
{
	int t[n+1][k+1];

	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=min(i , k);j++)
		{
			if(j == 0 || j == i)
			{
				t[i][j] = 1;
			}

			else
			{
				t[i][j] = t[i-1][j-1] + t[i-1][j];
			}
		}
	}

	return t[n][k];
}

int better(int n , int k)
{
	int c[k+1];

	memset(c , 0 , sizeof(c));

	c[0] = 1;

	for(int i = 1;i<= n ;i++)
	{
		for(int j = min(i,k);j > 0;j--)
		{
			c[j] = c[j] + c[j-1];
		}
	}

	return c[k];
}

int main()
{
	int n,k;
	cin >> n >> k;

	memset(dp , -1 , sizeof(dp));

	cout << recur(n , k) << endl;
	cout << memo(n , k) << endl;
	cout << top(n , k) << endl;
	cout << better(n , k) << endl;
	
}