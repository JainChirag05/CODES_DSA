#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector<int> adj[] , int V)
{
	vector<int> ans(V , -1);
	vector<bool> booked(V , 0);

	ans[0] = 0;
	int num = 0;
	booked[0] = true;

	for(int i = 1;i<V;i++)
	{
		for(auto x : adj[i])
		{
			if(ans[x] != -1)
			{
				booked[ans[x]] = true;
			}
		}

		int col;

		for(col = 0;col<V;col++)
		{
			if(booked[col] == false)
			{
				break;
			}
		}

		ans[i] = col;
		booked[col] = true;

		num = max(num , col+1);

		for(auto x : adj[i])
		{
			if(ans[x] != -1)
			{
				booked[ans[x]] = false;
			}
		}

	}

	cout << num << endl;

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
}

int main()
{
	int v , e;
	cin >> v >> e;

	vector<int> graph[v];

	for(int i = 0;i<e;i++)
	{
		int a , b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	solve(graph , v);
	
}