#include <bits/stdc++.h>
#define ll long long int

using namespace std;


//multiple occurences of same item allowed
int solve(int arr[] , int val[] , int n , int w)
{
	int t[n+1][w+1];

	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=w;j++)
		{
			if(i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=w;j++)
		{
			if(j >= arr[i-1])
			{
				int val1 = val[i-1] + t[i][j-arr[i-1]];
				int val2 = t[i-1][j];
				t[i][j] = max(val1 , val2);
			}

			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}

	return t[n][w];
}

int main()
{
	int n;
	cin >> n;

	int w;
	cin >> w;

	int arr[n];
	int val[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	for(int i = 0;i<n;i++)
	{
		cin >> val[i];
	}

	cout << solve(arr , val , n , w);
	
}