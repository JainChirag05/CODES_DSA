#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int wt[] , int val[] , int n, int w)
{
	int t[n+1][w+1];

	for(int i = 0;i<n+1;i++)
	{
		for(int j = 0;j<w+1;j++)
		{
			t[i][j] = -1;
		}
	}

	if(n==0 || w == 0)
	{
		return 0;
	}

	if(t[n][w] != -1)
	{
		return t[n][w];
	}

	else
	{
		if(wt[n-1] <= w)
		{
			int val1 = val[n-1] + solve(wt , val , n-1 , w-wt[n-1]);
			int val2 = solve(wt , val , n-1 , w);

			t[n][w] = max(val1 , val2);
		}

		else
		{
			t[n][w] = solve(wt , val , n-1 , w);
		}

		return t[n][w];
	}
}

int main()
{
	int n;
	cin >> n;

	int w;
	cin >> w;

	int wt[n];
	int val[n];

	for(int i = 0;i<n;i++)
	{
		cin >> wt[i];
	}

	for(int i = 0;i<n;i++)
	{
		cin >> val[i];
	}

	cout << solve(wt , val , n , w) << endl;
	
}