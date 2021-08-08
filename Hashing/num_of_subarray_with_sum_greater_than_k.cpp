#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n, int k)
{
	int ans = 0;

	for(int i = 1;i<n;i++)
	{
		arr[i] += arr[i-1];

		if(arr[i] > k)
		{
			ans++;
		}
	}

	if(arr[0] > k)
	{
		ans++;
	}

	sort(arr , arr+n);

	for(int i = 0;i<n;i++)
	{
		ans += n - (upper_bound(arr , arr+n , arr[i] + k) - arr);
	}

	cout << ans << endl;
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

	solve(arr , n , k);
	
}