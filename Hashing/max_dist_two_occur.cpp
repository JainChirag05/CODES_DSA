#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(int arr[] , int n)
{
	unordered_map<int,int> m;
	int ans = 0;

	for(int i =0;i<n;i++)
	{
		if(m.find(arr[i]) == m.end())
		{
			m[arr[i]] = i;
		}

		else
		{
			ans = max(ans , i - m[arr[i]]);
		}
	}

	cout << ans << endl;
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