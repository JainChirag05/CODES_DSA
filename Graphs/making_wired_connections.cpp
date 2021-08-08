#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void dfs(int st , vector<int> g[] , vector<int> &vis)
{
	vis[st] = 1;

	for(auto x :g[st])
	{
		if(vis[x] == 0)
		{
			dfs(x , g , vis);
		}
	}
}

int solve(int n , vector<vector<int>> edges)
{
	int m = edges.size();

	if(m < n-1)
	{
		return -1;
	}

	vector<int> g[n];

	for(int i = 0;i<m;i++)
	{
		g[edges[i][0]].push_back(edges[i][1]);
		g[edges[i][1]].push_back(edges[i][0]);
	}

	int count = 0;

	vector<int> vis(n,  0);

	for(int i = 0;i<n;i++)
	{
		if(vis[i] == 0)
		{
			count++;
			dfs(i , g , vis);
		}
	}

	return count - 1;
}

int main()
{
	int n , m;
	cin >> n >> m;

	vector<vector<int>> edges;

	for(int i = 0;i<n;i++)
	{
		vector<int> temp;

		for(int j = 0; j < 2;j++)
		{
			int t;
			cin >> t;
			temp.push_back(t);
		}

		edges.push_back(temp);
	}

	cout << solve(n , edges);	
}