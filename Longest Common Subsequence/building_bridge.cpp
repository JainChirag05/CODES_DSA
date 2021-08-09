#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(pair<int,int> arr[] , int n)
{
	sort(arr , arr+n);

	int t[n];

	for(int i = 0;i<n;i++)
	{
		t[i] = 1;
	}

	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[j].second < arr[i].first)
			{
				t[i] = max(t[i] , 1 + t[j]);
			}
		}
	}

	int ans = INT_MIN;

	for(int i = 0;i<n;i++)
	{
		ans = max(ans , t[i]);
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;

	pair<int,int> arr[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	cout << solve(arr , n);
	
}