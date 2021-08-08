#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void bfs(vector<int> adj[] , int v , vector<int> &visited)
{
	queue <int> q;
	q.push(v);
	visited[v] = 1;

	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		cout << x << " ";

		for(auto i : adj[x])
		{
			if(visited[i] == false)
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}


int main()
{
	int v , e;
	cin >> v >> e;

	vector<int> adj[v];
	vector<int> visited(v, 0);

	for(int i = 0;i<e;i++)
	{
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	bfs(adj , 0 , visited);
	
}