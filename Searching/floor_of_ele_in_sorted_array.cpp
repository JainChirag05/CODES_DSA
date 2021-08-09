#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int floor(int arr[] , int n , int val)
{
	int res = -1;
	int l = 0;
	int h = n-1;

	while(l <= h)
	{
		int m = l + (h-l)/2;

		if(arr[m] == val)
		{
			return arr[m-1];
		}

		else if(arr[m] < val)
		{
			res = arr[m];
			l = m + 1;
		}

		else
		{
			h = m-1;
		}
	}

	return res;
}

int ceil(int arr[] , int n , int val)
{
	int res = -1;
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
			res = arr[m];
			h = m-1;
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

	cout << floor(arr , n ,val) << endl;
	cout << ceil(arr , n , val) << endl;
	
}