//for sorted array

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector<int> arr)
{
	int ans = 2;
	int n = arr.size();
	int dp[n][n];

	for(int i = 0;i<n;i++)
	{
		dp[i][n-1] = 2;
	}

	for(int j = n-2;j>=1;j--)
	{
		int i = j-1;
		int k = j+1;

		while(i >= 0 && k <= n-1)
		{
			if(2*arr[j] == arr[i] + arr[k])
			{
				dp[i][j] = dp[j][k] + 1;
				ans = max(ans , dp[i][j]);
				i--;
				k++;
			}

			else if(2*arr[j] > arr[i]+arr[k])
			{
				k++;
			}

			else
			{
				dp[i][j] = 2;
				i--;
			}

		}

		while(i >= 0)
		{
			dp[i][j] = 2;
			i--;
		}
	}

	cout << ans;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n,0);

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	solve(arr);
	
}