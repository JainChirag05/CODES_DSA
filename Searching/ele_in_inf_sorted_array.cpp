#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int bin(int arr[] , int st , int end , int val)
{
	while(st <= end)
	{
		int mid = st + (end - st)/2;

		if(arr[mid] == val)
		{
			return mid;
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

	return -1;
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
	int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,140, 160, 170};

	int val = 110;

	int ans = search(arr , val);

	if(ans != -1)
	{
		cout << ans << endl;
	}

	else
	{
		cout << "None";
	}
}