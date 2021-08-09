#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string mp[] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

void solve(vector<string> &ans , int ind , vector<int> input , int n , string curr)
{
	if(ind == n)
	{
		ans.push_back(curr);
		return;
	}

	for(int i = 0;i<mp[input[ind]].size();i++)
	{
		curr.push_back(mp[input[ind]][i]);
		solve(ans , ind+1 , input , n , curr);
		curr.pop_back();
	}
}

void final(vector<int> input , int n)
{
	vector<string> ans;
	string curr = "";
	solve(ans , 0 , input , n , curr);

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> input(n);

	for(int i = 0;i<n;i++)
	{
		cin >> input[i];
	}

	final(input , n);
	
}