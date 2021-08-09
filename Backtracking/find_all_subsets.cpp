#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(set<vector<int>> &s , vector<int> temp , vector<int> arr , int n , int ind)
{
	if(ind == n)
	{
		sort(temp.begin() , temp.end());
		s.insert(temp);
		return;
	}

	solve(s,temp,arr,n,ind+1);
	temp.push_back(arr[ind]);
	solve(s,temp,arr,n,ind+1);
	temp.pop_back();
}

void final(vector<int> arr , int n)
{
	set<vector<int>> s;
	vector<vector<int>> ans;
	vector<int> temp;

	solve(s,temp,arr,n,0);

	for(auto i : s)
	{
		ans.push_back(i);
	}

	for(int i = 0;i<ans.size();i++)
	{
		for(int j = 0;j<ans[i].size();j++)
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

	vector<int> arr(n,0);

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	final(arr,n);
}