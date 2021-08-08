#include <bits/stdc++.h>
#define ll long long int
#define V 5

using namespace std;

void add(vector<pair<int , int>> arr[] , int u , int v , int weight)
{
	arr[u].push_back({v , weight});
}

int main()
{
	vector<pair<int , int>> arr[V];

	add(arr , 0 , 1 , 1);
	add(arr , 0 , 4 , 5);
	add(arr , 1 , 1 , 2);
	add(arr , 1 , 2 , 3);
	add(arr , 1 , 3 , 4);
	add(arr , 1 , 4 , 2);
	add(arr , 3 , 2 , 2);
	add(arr , 3 , 4 , 3);

	for(int i = 0;i<V;i++)
	{
		cout << i;

		for(int j = 0;j<arr[i].size();j++)
		{
			cout << " -> " << arr[i][j].first << "," << arr[i][j].second;
		}

		cout << endl;
	}

	
}