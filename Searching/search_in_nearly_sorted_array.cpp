#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int val)
{
	int l = 0;
	int r = n-1;

	while(l <= r)
	{
		int mid = l + (r-l)/2;

		if(arr[mid] == val)
		{
			return mid;
		}

		else if(mid+1 <= r && arr[mid+1] == val)
		{
			return mid+1;
		}

		else if(mid - 1 >= l && arr[mid-1] == val)
		{
			return mid - 1;
		}

		else if(arr[mid] < val)
		{
			l = mid +2 ;
		}

		else
		{
			r = mid-2;
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