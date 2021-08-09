#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int x)
{
	int l = 0;
	int h = n-1;

	while(l <= h)
	{
		int mid = l + (h-l)/2;

		if(arr[mid] == x)
		{
			return mid;
		}

		if(arr[mid] <= arr[h])
		{
			if(arr[mid] <= x && arr[h] >= x)
			{
				l = mid + 1;
			}

			else
			{
				h = mid - 1;
			}
		}

		else
		{
			if(arr[mid] >= x && arr[l] <= x)
			{
				h = mid - 1;
			}

			else
			{
				l = mid + 1;
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

	int val;
	cin >> val;

	cout << solve(arr , n , val);
}