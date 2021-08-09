#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int a[] , int n)
{
	if(n == 0)
	{
		return 0;
	}
	
	int lis[n];

	for(int i = 0;i<n;i++)
	{
		lis[i] = 1;
	}

	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(a[i] > a[j])
			{
				lis[i] = max(lis[i] , 1 + lis[j]);
			}
		}
	}

	int lds[n];

	for(int i = 0;i<n;i++)
	{
		lds[i] = 1;
	}

	for(int i = n-2;i>=0;i--)
	{
		for(int j = n-1;j>i;j--)
		{
			if(a[i] > a[j])
			{
				lds[i] = max(lds[i] , 1 + lds[j]);
			}
		}
	}

	int ans = lds[0] + lis[0] - 1;

	for(int i = 1;i<n;i++)
	{
		ans = max(ans , lds[i] + lis[i] - 1);
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

	cout << solve(arr , n);
	
}