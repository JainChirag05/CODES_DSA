#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n, vector<vector<int>> &ans , int ind , int x , vector<int> &sol)
{
	set<vector<int>> s;

	if(ind == n && x == 0)
	{
		sort(sol.begin() , sol.end());

		if(s.find(sol) == s.end())
		{
			ans.push_back(sol);
			s.insert(sol);
		}

		return;
	}

	if(arr[ind] <= x)
	{
		sol.push_back(arr[ind]);
		solve(arr , n , ans , ind+1 , x-arr[ind] , sol);
		sol.pop_back();
	}

	solve(arr , n , ans , ind+1 , x , sol);
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

	int x;
	cin >> x;

	vector<vector<int>> ans;
	vector<int> sol;

	solve(arr,n,ans,0,x,sol);

	for(int i = 0;i<ans.size();i++)
	{
		for(int j = 0;j<ans[i].size();j++)
		{
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}
	
}