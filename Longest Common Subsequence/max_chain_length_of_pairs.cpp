#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool comp(pair<int,int> a , pair<int,int> b)
{
	return b.second > a.second;
}

void solve(pair <int,int> arr[] , int n)
{
	sort(arr , arr+n , comp);
	int t[n];

	for(int i = 0;i<n;i++)
	{
		t[i] = 1;
	}

	for(int i = 1;i<n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			if(arr[i].first >= arr[j].second)
			{
				t[i] = max(t[i] , t[j] + 1);
			}
		}
	}

	int ans = INT_MIN;

	for(int i = 0;i<n;i++)
	{
		ans = max(ans , t[i]);
	}

	cout << ans;
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

	solve(arr , n);
	
}