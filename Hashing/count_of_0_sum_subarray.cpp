#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n)
{
	unordered_map <int,int> mp;

	int sum = 0;

	int i = 0;

	int ans = 0;

	mp[0] = 1;

	while(i < n)
	{
		sum += arr[i];

		if(mp.find(sum) != mp.end())
		{
			ans += mp[sum];
			mp[sum]++;
		}

		else
		{
			mp[sum]++;
		}

		i++;
	}

	cout << ans;
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

	solve(arr , n);
}