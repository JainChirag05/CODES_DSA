#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int x)
{
	int l = 0;
	int h = n-1;
	int ans = 0;

	while(l <= h)
	{
		int m = l + (h-l)/2;

		if(arr[m] <= x)
		{
			ans = m + 1;
			l = m + 1;
		}

		else
		{
			h = m - 1;
		}
	}

	return ans;
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

	int x;
	cin >> x;

	cout << solve(arr , n , x);
	
}