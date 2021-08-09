#include <bits/stdc++.h>
#define ll long long int

using namespace std;


void solve(int w, int x, int y , int z , int last)
{
	if(x == 0 && y == 0 && w == 0 && z == 0)
	{
		return 1;
	}

	if(last == 0) //last animal is w
	{
		ans += solve(w , x-1,y,z,1) + solve(w,x,y-1,z,2) + solve(w,x,y,z-1,3);
	}

	else if(last == 1) //last animal is x
	{
		ans += solve(w-1,x,y,z,0) + solve(w,x,y-1,z,2) + solve(w,x,y,z-1,3);
	}

	else if(last == 2) //last animal is y
	{
		ans += solve(w-1,x,y,z,0) + solve(w,x-1,y,z,1) + solve(w,x,y,z-1,3);
	}

	else if(last == 3) //last animal is z
	{
		ans += solve(w-1,x,y,z,0) + solve(w,x-1,y,z,1) + solve(w,x,y-1,z,2);
	}

	return ans;
}

int main()
{
	
}