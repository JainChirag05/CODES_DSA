#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool isvalid(int arr[] , int n , int mid  ,int k)
{
	int painter = 1;
	int sum = 0;

	for(int i = 0;i<n;i++)
	{
		if(sum > mid)
		{
			sum = arr[i];
			painter++;

			if(painter > k)
			{
				return false;
			}
		}

		else
		{
			sum += arr[i];
		}
	}

	return true;
}

int solve(int arr[] , int n , int k)
{
	int sum = 0;
	int maxi = 0;

	for(int i =0;i<n;i++)
	{
		sum += arr[i];

		maxi = max(maxi , arr[i]);
	}

	int st = maxi;
	int end = sum;
	int ans = INT_MAX;

	while(st <= end)
	{
		int mid = st + (end-st)/2;

		if(isvalid(arr , n , mid , k))
		{
			ans = min(ans , mid);
			end = mid-1;
		}

		else
		{
			st = mid + 1;
		}
	}

	return ans;
}

int main()
{
	
}