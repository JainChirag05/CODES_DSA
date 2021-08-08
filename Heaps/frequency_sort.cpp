#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n)
{
	unordered_map <int,int> mp;

	for(int i =0;i<n;i++)
	{
		mp[arr[i]]++;
	}

	vector<pair<int,int>> res;

	for(auto x : mp)
	{
		res.push_back({x.second , x.first});
	}

	sort(res.begin() , res.end()); // use priority_queue

	vector<int> ans;

	for(int i = 0;i<res.size();i++)
	{
		ans.push_back(res[i].second);
	}

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
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

	solve(arr , n);

}