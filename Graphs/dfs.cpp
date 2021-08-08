#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void dfs_iter(vector<int> adj[] , int v)
{
	vector<int> visited(adj->size(), 0);
	stack <int> st;

	st.push(v);
	visited[v] = 1;

	while(!st.empty())
	{
		int x = st.top();
		cout << x << " ";
		st.pop();

		for(auto i : adj[x])
		{
			if(visited[i] == 0)
			{
				st.push(i);
				visited[i] = 1;
			}
		}
	}
}

void dfs_recur(vector<int> adj[] , vector<int> &vis , int v) //prints in order from left to right
{
	vis[v] = 1;

	cout << v << " ";

	for(auto i : adj[v])
	{
		if(vis[i] == 0)
		{
			dfs_recur(adj , vis , i);
			vis[i] = 1;
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
	}

	vector<int> vis (adj->size() , 0);

	dfs_iter(adj , 1);
	cout << endl;
	dfs_recur(adj , vis , 1);
}

