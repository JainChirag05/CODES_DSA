#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int max_find(int arr[] , int n)
{
	int ans = INT_MIN;

	for(int i = 0;i<n;i++)
	{
		ans = max(ans , arr[i]);
	}

	return ans;
}

int total(int arr[] , int n)
{
	int sum = 0;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];
	}

	return sum;
}

bool valid(int arr[] , int n , int k , int mid)
{
	int s = 1;

	int sum = 0;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];

		if(sum > mid)
		{
			s++;
			sum = arr[i];
		}

		if(s > k)
		{
			return false;
		}
	}

	return true;
}

int solve(int arr[] , int n , int k)
{
	if(n < k)
	{
		return -1;
	}

	int res = -1;
	int st = max_find(arr , n);
	int end = total(arr , n);

	while(st <= end)
	{
		int mid = st + (end - st)/2;

		if(valid(arr , n , k , mid))
		{
			res = mid;
			end = mid - 1;
		}

		else
		{
			st = mid + 1;
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

	int k;
	cin >> k;

	cout << solve(arr , n ,k);
	
}