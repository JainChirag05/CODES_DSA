#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<int> order;

void dfs(int st , vector<int> &vis ,vector<int> adj[])
{
	vis[st] = 1;

	for(auto x : adj[st])
	{
		if(vis[x] == 0)
		{
			dfs(x , vis , adj);
		}
	}

	order.push_back(st);
}

void solve(vector<int> adj[] , int v)
{
	order.clear();

	vector<int> rev[v];

	for(int i = 0;i<v;i++)
	{
		for(auto j : adj[i])
		{
			rev[j].push_back(i);
		}
	}

	vector<int> vis(v , 0);

	for(int i = 0;i<v;i++)
	{
		if(vis[i] == 0)
		{
			dfs(i , vis , adj);
		}
	}

	vector<int> vis1(v , 0);

	int ans = 0;

	for(int i = v-1;i>=0;i--)
	{
		if(vis1[order[i]] == 0)
		{
			dfs(order[i] , vis1 , rev);
			ans++;
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

