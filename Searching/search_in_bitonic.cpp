#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int bin_inc(int arr[]  , int l , int h , int key)
{
	while(l <= h)
	{
		int mid = l + (h-l)/2;

		if(arr[mid] == key)
		{
			return mid;
		}

		else if(arr[mid] < key)
		{
			l = mid + 1;
		}

		else
		{
			h = mid - 1;
		}
	}

	return -1;
}

int bin_dec(int arr[]  , int l , int h , int key)
{
	while(l <= h)
	{
		int mid = l + (h-l)/2;

		if(arr[mid] == key)
		{
			return mid;
		}

		else if(arr[mid] > key)
		{
			l = mid + 1;
		}

		else
		{
			h = mid - 1;
		}
	}

	return -1;
}


int peak(int arr[] , int n)
{
	int l = 0;
	int h = n-1;

	while(l <= h)
	{
		int mid = l + (h-l)/2;

		if(mid > 0 && mid < n-1)
		{
			if(arr[mid] >= arr[mid+1] && arr[mid] >= arr[mid-1])
			{
				return mid;
			}

			else if(arr[mid+1] > arr[mid])
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
			if(arr[0] >= arr[1])
			{
				return 0;
			}

			else
			{
				return 1;
			}
		}

		else if(mid == n-1)
		{
			if(arr[n-1] >= arr[n-2])
			{
				return n-1;
			}

			else
			{
				return n-2;
			}
		}
	}

	return -1;
}

int final(int arr[] , int n , int key)
{
	int piv = peak(arr , n);

	if(piv == -1)
	{
		return bin_inc(arr , 0 , n-1 , key);
	}

	else
	{
		int fir = bin_inc(arr , 0 , piv , key);
		int sec = bin_dec(arr , piv , n-1 , key);

		if(fir != -1)
		{
			return fir;
		}

		else
		{
			return sec;
		}
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

	int key;
	cin >> key;

	cout << final(arr , n , key);
	
}