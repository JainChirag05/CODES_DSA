#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int bin(int arr[] , int st , int end , int val) //first occurence
{
	int res = -1;

	while(st <= end)
	{
		int mid = st + (end - st)/2;

		if(arr[mid] == val)
		{
			res = mid;
			end = mid - 1;
		}

		else if(arr[mid] < val)
		{
			st = mid + 1;
		}

		else
		{
			end = mid - 1;
		}
	}

	return res;
}

int search(int arr[] , int val)
{
	int st = 0;
	int end = 1;

	while(val > arr[end])
	{
		st = end;
		end = end*2;
	}

	int ans = bin(arr , st , end ,val);

	return ans;
}

int main()
{
	int arr[] = {0,0,0,0,0,0,0,1,1,1,1,1};

	int val = 1;

	int ans = search(arr , 1);

	if(ans != -1)
	{
		cout << ans << endl;
	}

	else
	{
		cout << "None";
	}
}