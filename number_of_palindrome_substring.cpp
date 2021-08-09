#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int dp[101][101];

int solve(string s , int i , int j)
{
	if(i > j)
	{
		return 1;
	}

	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}

	if(s[i] != s[j])
	{
		return dp[i][j] = 0;
	}

	return dp[i][j] = solve(s , i+1 , j-1);
}

int final(string s)
{
	int n = s.length();
	int ans = 0;

	memset(dp , -1 , sizeof(dp));

	for(int i = 0;i<n;i++)
	{
		for(int j = i + 1;j<n;j++)
		{
			if(solve(s , i , j))
			{
				ans++;
			}
		}
	}

	return ans;
}

int main()
{
	string s;
	cin >> s;

	cout << final(s) << endl;	
}