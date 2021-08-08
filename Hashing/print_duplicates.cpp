#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(int arr[] , int n)
{
	unordered_map <int,int> freq;

	int ans = 0;

	for(int i = 0;i<n;i++)
	{
		freq[arr[i]]++;
	}

	for(auto i = freq.begin();i != freq.end();i++)
	{
		if(i->second >= 2)
		{
			ans++;
			cout << i->first << " ";
		}
	}

	if(ans == 0)
	{
		cout << -1 << endl;
	}
}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i =0;i<n;i++)
	{
		cin >> arr[i];
	}

	solve(arr , n);
	
}