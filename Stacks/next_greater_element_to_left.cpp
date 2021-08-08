#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void naive(int arr[] , int n)
{
	vector <int> ans;
	for(int i = 0;i<n;i++)
	{
		int next = -1;

		for(int j = i-1;j>=0;j--)
		{
			if(arr[j] > arr[i])
			{
				next = arr[j];
				break;
			}

		}

		cout << next << " ";
	}

}

void pro(int arr[] , int n)
{
	vector<int> v;
	stack <int> st;

	for(int i = 0;i<n;i++)
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

			if(!st.empty())
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

	for(int i = 0; i<v.size(); i++)
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