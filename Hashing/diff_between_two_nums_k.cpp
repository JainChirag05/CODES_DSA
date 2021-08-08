#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int k)
{
	unordered_set<int> s;

	for(int i = 0;i<n;i++)
	{
		if(s.find(arr[i] + k) != s.end())
		{
			return 1;
		}

		if(s.find(arr[i] - k) != s.end())
		{
			return 1;
		}

		s.insert(arr[i]);
	}

	return 0;
}

void solve_count(int arr[] , int n , int k)
{
	int count = 0;
	unordered_map<int,int> mp;

	for(int i = 0;i<n;i++)
	{
		mp[arr[i]]++;
	}

	for(auto it = mp.begin(); it != mp.end(); it++)
	{
		if(k == 0)
		{
			if(it->second > 1)
			{
				count++;
			}
		}

		else
		{
			if(mp.find(it->first - k) != mp.end())
			{
				count++;
			}
		}
	}

	cout <<  count;
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

	cout << solve(arr , n , k);
	cout << endl;
	solve_count(arr , n , k);
	
}