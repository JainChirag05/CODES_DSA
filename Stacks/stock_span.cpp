#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll n;
	cin >> n;

	int price[n];

	for(int i = 0;i<n;i++)
	{
		cin >> price[i];
	}

	int ans[n];

	//ans[0] = 1;

	for(int i = 0;i<n;i++)
	{
		int count = 0;
		for(int j = i;j>=0;j--)
		{
			if(price[i] >= price[j])
			{
				count++;
			}

			else
			{
				break;
			}
		}

		ans[i] = count;
	}


	for(int i = 0;i<n;i++)
	{
		cout << ans[i] << " ";
	}
}