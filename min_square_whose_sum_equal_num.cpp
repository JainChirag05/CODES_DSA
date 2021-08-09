#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int recur(int n)
{
	int a = sqrt(n);

	if(a*a == n)
	{
		return 1;
	}

	if(n <= 3)
	{
		return n;
	}

	int ans = n;

	for(int i = 1;i*i<=n;i++)
	{
		ans = min(ans , 1 + recur(n - i*i));
	}

	return ans;
}

int solve(int n)
{
	if(n <= 3)
	{
		return n;
	}

	int dp[n+1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for(int i = 4;i<=n;i++)
	{
		dp[i] = i;

		for(int j = 1;j*j<=i;j++)
		{
			dp[i] = min(dp[i] , 1 + dp[i - j*j]);
		}
	}

	return dp[n];
}

int main()
{
	int n;
	cin >> n;

	cout << solve(n);

	cout << endl;

	cout << recur(n);	
}