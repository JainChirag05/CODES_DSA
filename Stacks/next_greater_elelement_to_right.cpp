#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void naive(int arr[] , int n)
{
	vector <int> ans;

	for(int i = 0;i<n;i++)
	{
		int res = -1;

		for(int j = i+1;j<n;j++)
		{
			if(arr[j] > arr[i])
			{
				res = arr[j];
				break;
			}
		}

		cout << res << " ";
	}
}

void pro(int arr[] , int n)
{
	vector<int> v;
	stack <int> st;

	for(int i = n-1;i>=0;i--)
	{
		if(st.empty())
		{
			v.push_back(-1);
		}

		else if(!st.empty() && st.top() > arr[i])
		{
			v.push_back(st.top());
		}

		else if(!st.empty() && st.top() <= arr[i])
		{
			while(st.top() <= arr[i] && st.empty() != 0)
			{
				st.pop();
			}

			if(st.empty())
			{
				v.push_back(-1);
			}

			else
			{
				v.push_back(st.top());
			}
		}

		st.push(arr[i]);

	}

	for(int i = v.size()-1;i>=0;i--)
	{	
		cout << v[i] << " ";
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

	naive(arr , n);
	cout << endl;
	pro(arr , n);
	
}