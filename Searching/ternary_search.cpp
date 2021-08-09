#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int l , int r , int k)
{
	while(l <= r)
	{
		int m1 = l + (r-l)/3;
		int m2 = r - (r-l)/3;

		if(arr[m1] == k)
		{
			return m1;
		}

		if(arr[m2] == k)
		{
			return m2;
		}

		if(k < arr[m1])
		{
			r = m1 - 1;
		}

		else if(arr[m2] < k)
		{
			l = m2 + 1;
		}

		else
		{
			l = m1 + 1;
			r = m2 - 1;
		}
	}

	return -1;
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

	int k;
	cin >> k;

	cout << solve(arr , 0 , n-1 , k);
}