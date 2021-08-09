#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int solve(int wt[] , int val[] , int n , int w)
{
	if(n == 0 || w == 0)
	{
		return 0;
	}

	if(wt[n-1] <= w)
	{
		return max((val[n-1] + solve(wt , val , n-1 , w-wt[n-1])) , solve(wt , val , n-1 , w));
	}

	else
	{
		return solve(wt , val , n-1 , w);
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