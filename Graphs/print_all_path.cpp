#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int st , int end , vector<int> &vis , vector<int> &ans , set<vector<int>> &s ,vector<int> graph[])
{
	ans.push_back(st);
	vis[st] = 1;

	if(st == end)
	{
		if(ans.size() == 0)
		{
			cout << "No Path";
		}

		else
		{
			s.insert(ans);
		}
	}

	else
	{
		for(auto i : graph[st])
		{
			if(vis[i] == 0)
			{
				solve(i , end , vis , ans , s,  graph);
			}
		}
	}

	ans.pop_back();
	vis[st] = 0;
}

int main()
{
	int v , e;
	cin >> v >> e;
	vector<int> graph[v];

	for(int i = 0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;

		graph[a].push_back(b);
	}

	vector<int> vis(v,  0);
	vector<int> ans;
	set<vector<int>> s;

	vector<vector<int>> res;

	solve(0,v-1,vis,ans , s,graph);

	for(auto it : s)
	{
		res.push_back(it);
	}	

	for(int i = 0;i<res.size();i++)
	{
		for(int j = 0;j<res[i].size()-1;j++)
		{
			cout << res[i][j] << " -> ";
		}

		cout << res[i][res[i].size()-1] << endl;
	}
}