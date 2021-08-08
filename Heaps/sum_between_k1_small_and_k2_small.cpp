#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n , int k)
{
	priority_queue <int> maxh;

	for(int i = 0;i<n;i++)
	{
		maxh.push(arr[i]);

		if(maxh.size() > k)
		{
			maxh.pop();
		}
	}

	return maxh.top();
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

	int k1;
	cin >> k1;

	int k2;
	cin >> k2;

	cout << solve(arr , n , k1) + solve(arr , n ,k2) << endl;
	
}