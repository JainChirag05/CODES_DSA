#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int k) //works for only positive nums
{
	int sum = 0;
	int i = 0;
	int j = 0;

	int ans = INT_MIN;

	while(j < n)
	{
		sum += arr[j];

		if(sum < k)
		{
			j++;
		}

		else if(sum == k)
		{
			ans = max(ans , j-i+1);
			j++;
		}

		else if(sum > k)
		{
			while(sum > k)
			{
				sum = sum - arr[i];
				i++;
			}

			j++;
		}
	}

	return ans;
}

int better(int arr[] , int n , int k)
{
	unordered_map <int,int> mp;

	int sum = 0;
	int res = 0;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];

		if(sum == k)
		{
			res = i - 0 + 1;
		}

		if(mp.find(sum) == mp.end())
		{
			mp[sum] = i;
		}

		if(mp.find(sum - k) != mp.end())
		{
			res = max(res , i - mp[sum - k]);
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

	cout << solve(arr,n,k) << endl;
	cout << better(arr,n,k) << endl;
	
}