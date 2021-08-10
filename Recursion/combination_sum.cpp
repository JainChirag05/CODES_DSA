//number can be chosen unlimited number of times

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void final(vector<int> &arr , vector<vector<int>> &ans , int ind , int x , vector<int> &sol)
{
	int n = arr.size();

	if(ind == n)
	{
		if(x == 0)
		{
			ans.push_back(sol);
		}

		return;
	}

	if(arr[ind] <= x) //picking the element
	{
		sol.push_back(arr[ind]);

		final(arr , ans , ind , x-arr[ind] , sol);

		sol.pop_back();
	}

	final(arr , ans , ind+1 , x , sol); //not picking
}

void solve(vector<int> &nums , int x)
{
	vector<vector<int>> ans;

	vector <int> sol;

	final(nums , ans , 0 , x , sol);

	for(int i = 0;i<ans.size();i++)
	{
		for(int j = 0;j<ans[0].size();j++)
		{
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> nums;

	for(int i = 0;i<n;i++)
	{
		int temp;
		cin >> temp;

		nums.push_back(temp);
	}

	int x;
	cin >> x;

	solve(nums , x);
	
}