#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int naive(int arr[] , int n)
{
	int ans = INT_MIN;

	for(int i = 0;i<n;i++)
	{
		int h = INT_MAX;

		for(int j = i;j<n;j++)
		{
			h = min(h , arr[j]);

			int len = j - i + 1;

			ans = max(ans , h*len);
		}
	}

	return ans;
}

int solve(int arr[] , int n)
{
	stack <int> st;
	long long int area = 0;
	long long int ans = 0;
	int i = 0;

	while(i < n)
	{
		if(st.empty() || arr[st.top()] < arr[i])
		{
			st.push(i++);
		}

		else
		{
			int t = st.top();
			st.pop();
			int h = arr[t];

			if(st.empty())
			{
				area = h*i;
			}

			else
			{
				area = h * (i - st.top() - 1);
			}
		}

		ans = max(area , ans);
	}

	while(!st.empty())
	{
		int t = st.top();
		st.pop();
		int h = arr[t];

		if(st.empty())
		{
			area = h*i;
		}

		else
		{
			area = h * (i - st.top() - 1);
		}

		ans = max(ans , area);
	}

	return ans;
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

	cout << solve(arr , n) << endl;
	cout << naive(arr , n) << endl;
	
}