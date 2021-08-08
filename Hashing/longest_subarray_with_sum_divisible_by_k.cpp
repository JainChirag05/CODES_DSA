#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n , int k)
{
	unordered_map<int,int> mp;

	int sum = 0;
	int ans = 0;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];

		int rem = sum % k;

		if(rem < 0)
		{
			rem += k;
		}

		if(mp.find(rem) != mp.end())
		{
			ans = max(ans , i - mp[rem]);
		}

		else
		{
			mp[rem] = i;
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