#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n)
{
	int lds[n];

	for(int i = 0;i<n;i++)
	{
		lds[i] = 1;
	}

	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[i] < arr[j])
			{
				lds[i] = max(lds[i] , 1 + lds[j]);
			}
		}
	}

	int ans = 0;

	for(int i = 0;i<n;i++)
	{
		ans = max(lds[i] , ans);
	}

	return ans;
}

int lds(int a[] , int b[] , int n , int m)
{
	int t[n+1][m+1];

	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=m;j++)
		{
			if(i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(a[i-1] == b[j-1])
			{
				t[i][j] = 1 + t[i-1][j-1];
			}

			else
			{
				t[i][j] = max(t[i-1][j] , t[i][j-1]);
			}
		}
	}

	return t[n][m];
}

int main()
{
	int n;
	cin >> n;

	int a[n];
	int b[n];

	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b , b+n , greater<int>());

	cout << solve(a , n) << endl;
	cout << lds(a,b,n,n) << endl;
	
}