//each number to be chosen once without duplicates

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector<int> &arr , vector<int> temp , int n , int ind , int x , set<vector<int>> &s , int sum)
{
	if(sum == x)
	{
		sort(temp.begin() , temp.end());
		s.insert(temp);
		return;
	}

	if(ind == n)
	{
		return;
	}

	if(sum + arr[ind] <= x)
	{
		temp.push_back(arr[ind]);
		solve(arr , temp , n , ind+1 , x , s , sum + arr[ind]);
		temp.pop_back();
	}

	solve(arr , temp , n , ind+1 , x , s , sum);
}

void final(vector<int> arr , int n , int x)
{
	vector<vector<int>> ans;
	set<vector<int>> s;
	vector<int> temp;

	solve(arr , temp , n , 0 , x , s , 0);

	for(auto i : s)
	{
		ans.push_back(i);
	}

	sort(ans.begin(), ans.end());
		
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

	final(nums , n , x);
	
}