#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n , int k)
{
	priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> hp;

	unordered_map <int,int> mp;

	for(int i = 0;i<n;i++)
	{
		mp[arr[i]]++;
	}

	for(auto i = mp.begin();i != mp.end(); i++)
	{
		hp.push({i->second , i->first});

		if(hp.size() > k)
		{
			hp.pop();
		}
	}

	while(!hp.empty())
	{
		cout << hp.top().second << " ";
		hp.pop();
	}

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

	solve(arr , n , k);
	
}