#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void dfs(vector<int> graph[] , vector<int> &vis , int st)
{
	vis[st] = 1;

	for(auto i : graph[st])
	{
		if(vis[i] == 0)
		{
			dfs(graph , vis , i);
		}
	}
}

void solve(vector<int> graph[] , int V)
{
	vector<int> vis(V , 0);

	int ans = 0;

	for(int i = 0;i<V;i++)
	{
		if(vis[i] == 0)
		{
			dfs(graph , vis , i);
			ans = i;
		}
	}

	for(int i = 0;i<V;i++)
	{
		vis[i] = 0;
	}

	dfs(graph , vis , ans);

	for(int i = 0;i<V;i++)
	{
		if(vis[i] == 0)
		{
			cout << "None";
		}
	}

	cout << ans;
}

int main()
{
	int v , e;
	cin >> v >> e;

	vector<int> adj[v];

	for(int i = 0;i<e;i++)
	{
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	solve(adj , v);	
}