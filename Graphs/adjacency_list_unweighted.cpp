//space is O(v + e)
//adding edge take O(1) time
//adding vertex take O(1) time
//checking for edge takes O(v)
//time to remove edge is O(e)


#include <bits/stdc++.h>
#define ll long long int
#define V 5

using namespace std;

void add(vector<int> arr[] , int u , int v)
{
	arr[u].push_back(v);
}

int main()
{
	vector<int> arr[V];

	add(arr , 0 , 1);
	add(arr , 0 , 4);
	add(arr , 1 , 1);
	add(arr , 1 , 2);
	add(arr , 1 , 3);
	add(arr , 1 , 4);
	add(arr , 3 , 2);
	add(arr , 3 , 4);

	for(int i = 0;i<V;i++)
	{
		cout << i;

		for(int j = 0;j<arr[i].size();j++)
		{
			cout << " -> " << arr[i][j];
		}

		cout << endl;
	}

	
}