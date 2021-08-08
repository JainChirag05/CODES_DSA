#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n , int k)
{
	unordered_map <int,int> mp;
	int len = 0;
	int st = -1;
	int end = -1;
	int sum = 0;
	vector<int> ans;

	for(int i = 0;i<n;i++)
	{
		sum += arr[i];

		if(sum == k)
		{
			len = i + 1;
			st = 0;
			end = i;
		}

		if(mp.find(sum-k) != mp.end())
		{
			if(len < i - mp[sum-k])
			{
				st = mp[sum-k] + 1;
				end = i;
				len = i - mp[sum-k];
			}
		}

		else
		{
			mp[sum] = i;
		}
	}

	for(int i = st;i<=end;i++)
	{
		ans.push_back(arr[i]);
	}

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}

	cout << endl;

	cout << ans.size();
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