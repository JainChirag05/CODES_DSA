#include <bits/stdc++.h>
#define ll long long int
using namespace std;


void solve(int arr[] , int n)
{
	unordered_map<int,int> m;

	for(int i = 0;i<n;i++)
	{
		m[arr[i]]++;
	}

	int ans = 0;

	for(auto i = m.begin();i!=m.end();i++)
	{
		ans = max(ans , i->second);
	}

	cout << n - ans << endl;
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

	solve(arr , n);
}