#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n)
{
	unordered_map <int,int> mp;

	for(int i = 0;i<n;i++)
	{
		mp[arr[i]]++;
	}

	int b[n];
	int k = 0;

	for(int i = 0;i<n;i++)
	{
		b[k++] = mp[arr[i]];
	}

	stack <int> st;
	unordered_map <int,int> mp2;

	st.push(b[0]);

	for(int i = 1;i<n;i++)
	{
		while(!st.empty() && st.top() < b[i])
		{
			mp2[st.top()] = b[i];
			st.pop();
		}

		st.push(b[i]);
	}

	while(!st.empty())
	{
		mp2[st.top()] = -1;
		st.pop();
	}

	for(int i = 0;i<n;i++)
	{
		cout << mp2[b[i]] << " ";
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
	
	solve(arr , n);
}