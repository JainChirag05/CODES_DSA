#include <bits/stdc++.h>
#define ll long long int
#define MAX 5

using namespace std;

vector<string> ans;

void dfs(int m[MAX][MAX] , int i , int j , string s , vector<vector<int>> &vis , int n)
{
	if(i < 0 || j < 0 || i > n-1 || j > n-1)
	{
		return;
	}

	if(m[i][j] == 0 || vis[i][j] == 1)
	{
		return;
	}

	if(i == n-1 && j == n-1)
	{
		ans.push_back(s);
		return;
	}

	vis[i][j] = 1;

	dfs(m , i , j-1 , s+'L' , vis , n);
	dfs(m , i , j+1 , s+'R' , vis , n);
	dfs(m , i-1 , j , s+'U' , vis , n);
	dfs(m , i+1 , j , s+'D' , vis , n);

	vis[i][j] = 0;
}

vector<string> paths(int m[MAX][MAX] , int n)
{
	ans.clear();
	vector<vector<int>> vis(0 , vector<int>(0));

	if(m[0][0] == 0 || m[n-1][n-1] == 0)
	{
		return ans;
	}

	string s = "";

	dfs(m , 0 , 0 , s , vis , n);

	sort(ans.begin() , ans.end());

	return ans;
}