#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n)
{
	int l = 0;
	int h = n-1;

	while(l <= h)
	{
		int mid = l + (h-l)/2;

		if(mid > 0 && mid < n-1)
		{
			if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1])
			{
				return mid;
			}

			else if(arr[mid] < arr[mid+1])
			{
				l = mid + 1;
			}

			else
			{
				h = mid - 1;
			}
		}

		else if(mid == 0)
		{
			if(arr[mid] >= arr[mid + 1])
			{
				return mid;
			}

			else 
			{
				return mid+1;
			}
		}

		else if(mid == n-1)
		{
			if(arr[mid] >= arr[mid - 1])
			{
				return mid;
			}

			else
			{
				return mid - 1;
			}

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

	cout << solve(arr , n);
	
}