#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector<int> adj[] , int v)
{
	vector<int> in(v+1 , 0);
	vector<int> ans(v+1, 0);

	for(int i = 1;i<=v;i++)
	{
		for(auto x : adj[i])
		{
			in[x]++;
		}
	}

	queue <int> q;

	for(int i = 1;i<=v;i++)
	{
		if(in[i] == 0)
		{
			q.push(i);
			ans[i] = 1;
		}
	}

	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		for(auto it : adj[x])
		{
			in[it]--;

			if(in[it] == 0)
			{
				q.push(it);
				ans[it] = ans[x] + 1;
			}
		}
	}

	for(int i = 1;i<=v;i++)
	{
		cout << ans[i] << " ";
	}
}
int main()
{
	int v , e;
	cin >> v >> e;

	vector<int> adj[v+1];

	for(int i = 0;i<e;i++)
	{
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	solve(adj , v);
}

