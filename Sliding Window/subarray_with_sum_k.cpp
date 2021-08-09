#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n , int k)
{
	int sum = 0;
	int count = 0;

	unordered_map <int,int> mp;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];

		if(sum == k)
		{
			count++;
		}

		if(mp.find(sum-k) != mp.end())
		{
			count += mp[sum-k];
		}

		mp[sum]++;
	}

	cout << count;
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

	solve(arr , n ,k);
}