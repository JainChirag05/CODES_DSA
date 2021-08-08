#include <bits/stdc++.h>


// or use catalan number

using namespace std;

int cal(int n)
{
	int num[n+1];
	
	memset(num , 0 , sizeof(num));
	
	num[0] = num[1] = 1;
	
	
	for(int i = 2;i<=n;i++)
	{
		for(int j = 0;j<i;j++)
		{
			num[i] += num[j] * num[i-j-1];
		}
	}
	
	return num[n];
}

int main()
{
    int n = 5;
    cout << "Total Possible Binary Trees are : " << cal(n) << endl;
    return 0;
}

