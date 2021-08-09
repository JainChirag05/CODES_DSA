#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int val)
{
	int l = 0;
	int h = n-1;

	while(l <= h)
	{
		int m = l + (h-l)/2;

		if(arr[m] == val)
		{
			return arr[m];
		}

		else if(arr[m] < val)
		{
			l = m + 1;
		}

		else
		{
			h = m-1;
		}
	}

	if(abs(arr[l] - val) < abs(arr[h] - val))
	{
		return arr[l];
	}

	else
	{
		return arr[h];
	}
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

	int val;
	cin >> val;

	cout << solve(arr , n , val) << endl;	
}