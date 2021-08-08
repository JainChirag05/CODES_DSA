#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int find(vector<int> &parent , int st)
{
	if(parent[st] == -1)
	{
		return st;
	}

	return find(parent , parent[st]);
}

void union_op(int from , int to , vector<int> &parent)
{
	from = find(parent , from);
	to = find(parent , to);
	parent[from] = to;
}

bool cycle(vector<pair<int,int>> &adj , vector<int> &parent)
{
	for(auto p : adj)
	{
		int from = find(parent , p.first);
		int to = find(parent , p.second);

		if(from == to)
		{
			return true;
		}

		union_op(from , to , parent);
	}

	return false;
}


int main()
{
	int v , e;
	cin >> v >> e;

	vector<pair<int,int>> adj;

	for(int i = 0;i<e;i++)
	{
		int a , b;
		cin >> a >> b;
		adj.push_back({a,b});
	}

	vector<int> parent(v , -1);

	cout << cycle(adj , parent);
}

