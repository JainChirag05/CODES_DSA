#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool f = 1;

void dfs(vector<int> adj[] , vector<int> &vis , int st , int par , int col)
{
	vis[st] = col;

	for(auto x : adj[st])
	{
		if(vis[x] == -1)
		{
			dfs(adj , vis , x , st , 3 - col);
		}

		else if(x != par && vis[x] == col)
		{
			f = 0;
			break;
		}
	}
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
		adj[b].push_back(a);
	}

	f = 1;

	vector<int> vis (v , -1);

	dfs(adj , vis , 0 , 0 , 1);

	cout << f;

}

