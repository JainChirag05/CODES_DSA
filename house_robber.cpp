#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n)
{
	if(n == 0)
	{
		cout << 0;
		return;
	}

	if(n == 1)
	{
		cout << arr[0];
		return;
	}

	if(n==2)
	{
		cout << max(arr[0] , arr[1]);
		return;
	}

	int dp[n];

	dp[0] = arr[0];
	dp[1] = max(arr[0] , arr[1]);


	for(int i = 2;i<n;i++)
	{
		dp[i] = max(dp[i-2] + arr[i] , dp[i-1]);
	}

	cout << dp[n-1];
}

void optimal(int arr[] , int n)
{
	int pp = 0;
	int p = arr[0];

	for(int i = 1;i<n;i++)
	{
		int curr = pp + arr[i];
		pp = max(pp , p);
		p = curr;
	}

	cout <<  max(pp , p);
}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	optimal(arr,n);
	cout << endl;
	solve(arr,n);
	
}