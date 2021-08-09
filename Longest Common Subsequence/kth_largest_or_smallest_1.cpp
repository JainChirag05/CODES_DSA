#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int smallest(int arr[] , int n , int k)
{
	priority_queue <int> h;

	for(int i = 0;i<n;i++)
	{
		h.push(arr[i]);

		if(h.size() > k)
		{
			h.pop();
		}
	}

	return h.top();
}

int large(int arr[] , int n , int k)
{
	priority_queue <int , vector <int> , greater<int>> hp;

	for(int i = 0;i<n;i++)
	{
		hp.push(arr[i]);

		if(hp.size() > k)
		{
			hp.pop();
		}
	}

	return hp.top();
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

	cout << smallest(arr , n , k) << endl;
	cout << large(arr , n , k) << endl;
}