#include <bits/stdc++.h>
#define ll long long int

using namespace std;

//equal to index of min element(left-rotated), also known as pivot

int solve(int arr[] , int n)
{
	int l = 0;
	int h = n-1;

	if(arr[l] <= arr[h])
	{
		return 0;
	}

	while(l <= h)
	{
		int mid = l + (h-l)/2;

		int next = (mid+1)%n;
		int prev = (mid + n -1)%n;		//To avoid overflow, we create a cycle

		if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
		{
			return mid;	//left rotated else return n-mid;
		}

		else if(arr[mid] >= arr[l])
		{
			l = mid +1 ;
		}

		else
		{
			h = mid - 1;
		}
	}

	return 0;
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