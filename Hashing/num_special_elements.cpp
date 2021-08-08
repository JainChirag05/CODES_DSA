//number which can be represented as sum of two or more consecutive elements

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector<int> arr)
{
	int n = arr.size();

	vector<int> prefix(n+1);
	vector<int> mp(n+1);

	for(int i = 1;i<=n;i++)
	{
		prefix[i] += prefix[i-1] + arr[i-1];
	}

	for(int i = 0;i<n;i++)
	{
		mp[arr[i]]++;
	}

	int ans = 0;

	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			int sum = prefix[j+1] - prefix[i];

			if(sum <= n && mp[sum] > 0)
			{
				ans++;
				mp[sum]--;
			}
		}
	}

	cout << ans << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	solve(arr);
	
}