#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s)
{
	int n = s.length();
	int maxlen = 1;
	int st = 0;

	int dp[n+1][n+1];

	memset(dp , 0 , sizeof(dp));

	for(int i = 0;i < n ;i++)
	{
		dp[i][i] = 1;
	}

	for(int i = 0;i<n-1;i++)
	{
		if(s[i] == s[i+1])
		{
			dp[i][i+1] = 1;
			st = i;
			maxlen = 2;
		}
	}

	for(int k = 3;k<=n;k++)
	{
		for(int i = 0;i<n-k+1;i++)
		{
			int j = i + k - 1;

			if(s[i] == s[j] && dp[i+1][j-1] == 1)
			{
				dp[i][j] = 1;

				if(k > maxlen)
				{
					maxlen = k;
					st = i;
				}
			}
		}
	}

	cout << maxlen << endl;
	cout << s.substr(st , maxlen);
}

int main()
{
	string s;
	cin >> s;

	solve(s);
	
}