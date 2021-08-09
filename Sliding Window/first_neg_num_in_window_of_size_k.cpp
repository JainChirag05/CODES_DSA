#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void brute(int arr[] , int n , int k)
{
	int flag = 0;

	for(int i = 0;i<n;i++)
	{
		for(int j = i ; j < i+k;j++)
		{
			if(arr[j] < 0)
			{
				flag = 1;
				cout << arr[j] << " ";
				break;
			}
		}

		if(flag == 0)
		{
			cout << 0 << " ";
		}
	}
}

void better(int arr[] , int n , int k)
{
	deque <int> q;

	int i = 0;
	int j = 0;

	while(j < n)
	{
		if(arr[j] < 0)
		{
			q.push_back(arr[j]);
		}

		if(j-i+1 < k)
		{
			j++;
			continue;
		}

		else if(j-i+1 == k)
		{
			if(q.size() == 0)
			{
				cout << 0 << " ";
			}

			else
			{
				cout << q.front() << " ";
			}

			if(arr[i] < 0)
			{
				q.pop_front();
			}

			i++;
			j++;
		}
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

	brute(arr , n , k);
	cout << endl;
	better(arr , n , k);
	
}