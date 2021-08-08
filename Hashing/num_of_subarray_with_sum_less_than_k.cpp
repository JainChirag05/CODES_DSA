#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n , int k)
{
	int st = 0;
	int end = 0;
	int sum = arr[0];
	int ans = 0;

	while(st < n && end < n)
	{
		if(sum < k)
		{
			end++;

			if(end >= st)
			{
				ans += end - st;
			}

			if(end < n)
			{
				sum += arr[end];
			}
		}

		else
		{
			sum -= arr[st];
			st++;
		}
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