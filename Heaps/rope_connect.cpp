#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n)
{
	priority_queue <int , vector<int> , greater<int>> hp;

	for(int i = 0;i<n;i++)
	{
		hp.push(arr[i]);
	}

	int cost = 0;

	while(hp.size() >= 2)
	{
		int first = hp.top();
		hp.pop();
		int sec = hp.top();
		hp.pop();

		cost += first + sec;
		hp.push(first + sec);
	}

	return cost;
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

	cout << solve(arr , n);
	
}