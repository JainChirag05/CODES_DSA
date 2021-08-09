#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int recur(string a , string b , int m , int n)
{
	if(n == 0)
	{
		return m;
	}

	if(m == 0)
	{
		return n;
	}

	if(a[m-1] == b[n-1])
	{
		return recur(a , b,  m-1 , n-1);
	}

	return 1 + min(min(recur(a,b,m,n-1) , recur(a,b,m-1,n)) , recur(a,b,m-1,n-1));
}

int better(string a , string b , int m , int n)
{
	int dp[m+1][n+1];

	for(int i = 0;i<=m;i++)
	{
		for(int j = 0;j<=n;j++)
		{
			if(i == 0)
			{
				dp[i][j] = j;
			}

			else if(j == 0)
			{
				dp[i][j] = i;
			}

			else if(a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}

			else
			{
				dp[i][j] = 1 + min(dp[i-1][j-1] , min(dp[i][j-1] , dp[i-1][j]));
			}
		}
	}

	return dp[m][n];
}

int main()
{
	string a;
	cin >> a;

	string b;
	cin >> b;

	int m = a.length();
	int n = b.length();

	cout << recur(a,b,m,n) << endl;
	cout << better(a,b,m,n) << endl;
	
}