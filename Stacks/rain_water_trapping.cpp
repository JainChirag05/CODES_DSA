#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int arr[] , int n)
{
	int i = 0;
	int ans = 0;
	stack <int> st;

	while(i < n)
	{
		while(!st.empty() && arr[st.top()] < arr[i])
		{
			int h = arr[st.top()];
			st.pop();

			if(st.empty())
			{
				break;
			}

			else
			{
				int len = i - st.top() - 1;

				ans += (min(arr[st.top()] , arr[i]) - h) * len;
			}
		}

		st.push(i);
		i++;
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
}