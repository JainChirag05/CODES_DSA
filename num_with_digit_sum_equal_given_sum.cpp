#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int naive(int n , int sum)
{
	if(n == 0)
	{
		return sum ==  0;
	}

	if(sum == 0)
	{
		return 1;
	}

	int ans = 0;

	for(int i = 0;i<=9;i++)
	{
		if(sum - i >= 0)
		{
			ans += naive(n-1 , sum - i);
		}

	}

	return ans;
}

int naive_final(int n , int sum)
{
	int ans = 0;

	for(int i = 1;i<=9;i++)
	{
		if(sum - i >= 0)
		{
			ans += naive(n-1 , sum - i);
		}

	}

	return ans;
}

int dp[101][1001];

int better(int n , int sum)
{
	if(n == 0)
	{
		return sum == 0;
	}

	if(dp[n][sum] != -1)
	{
		return dp[n][sum];
	}

	int ans = 0;

	for(int i = 0;i<=9;i++)
	{
		if(sum - i >= 0)
		{
			ans += better(n-1 , sum - i);
		}

	}

	return dp[n][sum] = ans;
}

int better_final(int n , int sum)
{
	if(n == 0)
	{
		return sum == 0;
	}

	if(dp[n][sum] != -1)
	{
		return dp[n][sum];
	}

	int ans = 0;

	for(int i = 1;i<=9;i++)
	{
		if(sum - i >= 0)
		{
			ans += better(n-1 , sum - i);
		}

	}

	return dp[n][sum] = ans;
}

int main()
{
	int n;
	cin >> n;

	int sum;
	cin >> sum;

	memset(dp , -1 , sizeof(dp));

	cout << naive_final(n , sum) << endl;
	cout << better_final(n , sum) << endl;
	
}