#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int first(int arr[] , int n , int val)
{
	int res = 0;
	int l = 0;
	int r = n-1;

	while(l <= r)
	{
		int mid = l + (r-l)/2;

		if(arr[mid] == val)
		{
			res = mid;
			r = mid - 1;
		}

		else if(arr[mid] < val)
		{
			l = mid + 1;
		}

		else
		{
			r = mid-1;
		}
	}

	return res;
}

int last(int arr[] , int n , int val)
{
	int res = 0;
	int l = 0;
	int r = n-1;

	while(l <= r)
	{
		int mid = l + (r-l)/2;

		if(arr[mid] == val)
		{
			res = mid;
			l = mid + 1;
		}

		else if(arr[mid] < val)
		{
			l = mid + 1;
		}

		else
		{
			r = mid-1;
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

	int fir = first(arr , n , val);
	int las = last(arr , n , val);

	cout << las - fir + 1 <<endl;
}