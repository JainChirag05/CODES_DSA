#include <bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>

using namespace std;

void addEdge(vector<pi> graph[] , int u , int v , int w)
{
	graph[u].push_back({v,w});
	graph[v].push_back({u,w});
}

void dijkstra(vector<pi> graph[] , int x , int V) //O(VlogE)
{
	priority_queue<pi , vector<pi> , greater<pi>> q;

	vector<int> val(V , INT_MAX);

	q.push({0 , x});
	val[x] = 0;

	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();

		for(auto i : graph[u])
		{
			int v = i.first;
			int wt = i.second;

			if(val[v] > val[u] + wt)
			{
				val[v] = val[u] + wt;
				q.push({val[v] , v});
			}
		}
	}

	for(int i = 0;i<V;i++)
	{
		cout << i << " " << " " << val[i] <<endl;
	}
}

int main()
{
    int V = 9;
    vector<pi> graph[V];

    addEdge(graph ,0, 1, 4); 
    addEdge(graph ,0, 7, 8); 
    addEdge(graph ,1, 2, 8); 
    addEdge(graph ,1, 7, 11); 
    addEdge(graph ,2, 3, 7); 
    addEdge(graph ,2, 8, 2); 
    addEdge(graph ,2, 5, 4); 
    addEdge(graph ,3, 4, 9); 
    addEdge(graph ,3, 5, 14); 
    addEdge(graph ,4, 5, 10); 
    addEdge(graph ,5, 6, 2); 
    addEdge(graph ,6, 7, 1); 
    addEdge(graph ,6, 8, 6); 
    addEdge(graph ,7, 8, 7); 

    dijkstra(graph, 0, 9);
}