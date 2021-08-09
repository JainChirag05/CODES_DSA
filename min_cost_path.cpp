#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int recur(vector<vector<int>> &arr , int n , int m)
{
	if(n < 0 || m < 0)
	{
		return -1;
	}

	else if(n == 0 && m == 0)
	{
		return arr[n][m];
	}

	else
	{
		return arr[n][m] + min(recur(arr , n-1 , m) , min(recur(arr ,n-1 , m-1) , recur(arr , n , m-1)));
	}
}

int better(vector<vector<int>> &arr , int n , int m) //use this
{
	int dp[n][m];
	dp[0][0] = arr[0][0];

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(i == 0 && j == 0)
			{
				continue;
			}

			else if(i == 0)
			{
				dp[i][j] = arr[i][j] + dp[i][j-1];
			}

			else if(j == 0)
			{
				dp[i][j] = arr[i][j] + dp[i-1][j];
			}

			else
			{
				dp[i][j] = arr[i][j] + min(dp[i][j-1] , min(dp[i-1][j] , dp[i-1][j-1]));
			}
		}
	}

	return dp[n-1][m-1];
}

int best(vector<vector<int>> &arr , int n , int m)
{
	for(int i = 1;i<n;i++)
	{
		arr[i][0] += arr[i-1][0];
	}

	for(int j = 1;j<m;j++)
	{
		arr[0][j] += arr[0][j-1];
	}

	for(int i = 1;i<n;i++)
	{
		for(int j = 1;j<m;j++)
		{
			arr[i][j] += min(arr[i-1][j-1] , min(arr[i-1][j] , arr[i][j-1]));
		}
	}

	return arr[n][m];
}

int main()
{
	int n,m;
	cin >> n >> m;

	vector<vector<int>> arr;

	for(int i = 0;i<n;i++)
	{
		vector<int> temp;

		for(int j = 0;j<m;j++)
		{
			int x;
			cin >> x;
			temp.push_back(x);
		}

		arr.push_back(temp);
	}

	cout << recur(arr , n , m) << endl;

	
}