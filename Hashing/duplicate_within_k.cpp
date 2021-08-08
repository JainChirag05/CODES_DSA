#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool solve(int arr[] , int n , int k)
{
	unordered_set <int> m;

	for(int i =0;i<n;i++)
	{
		if(m.find(arr[i]) != m.end())
		{
			return true;
		}

		m.insert(arr[i]);

		if(i >= k)
		{
			m.erase(arr[i-k]);
		}
	}

	return false;
}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	int k;
	cin >> k; 

	if(solve(arr , n , k) == true)
	{
		cout << "yep" << endl;
	}

	else
	{
		cout << "nope" << endl;
	}
}