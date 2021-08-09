#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int first(int arr[] , int n , int val)
{
	int res = 0;
	int l = 0;
	int h = n-1;

	while(l <= h)
	{
		int mid = l + (h-l)/2;

		if(arr[mid] == val)
		{
			res = mid;
			h = mid-1;
		}

		else if(val < arr[mid])
		{
			h = mid - 1;
		}

		else
		{
			l = mid + 1;
		}
	}

	return res;
}

int last(int arr[] , int n , int val)
{
	int res = 0;
	int l = 0;
	int h = n-1;

	while(l <= h)
	{
		int mid = l + (h-l)/2;

		if(arr[mid] == val)
		{
			res = mid;
			l = mid + 1;
		}

		else if(val < arr[mid])
		{
			h = mid - 1;
		}

		else
		{
			l = mid + 1;
		}
	}

	return res;
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

	cout << first(arr , n , val) <<endl;
	cout << last(arr , n , val) << endl;
}