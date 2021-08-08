#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n)
{
	int sum = 0;
	unordered_map<int,int> mp;
	int ans = 0;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];

		if(sum == 0)
		{
			ans = i + 1;
		}

		if(mp.find(sum) != mp.end())
		{
			ans = max(ans , i - mp[sum]);
		}

		else
		{
			mp[sum] = i;
		}
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