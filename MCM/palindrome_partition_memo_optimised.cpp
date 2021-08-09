#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool palin(string s , int i , int j)
{
	while(i < j)
	{
	    if(s[i] != s[j])
	    {
		    return false;
	    }

	    i++;
	    j--;
	}

	return true;
}

int t[501][501];
    
int solve(string s , int i, int j)
{
    int ans = INT_MAX;
    int temp;
        
    if(i >= j || palin(s , i , j))
    {
        return 0;
    }
        
    if(t[i][j] != -1)
    {
        return t[i][j];
    }
        
    for(int k = i;k<j;k++)
    {
    	int left;
    	int right;

    	if(t[i][k] != -1)
    	{
    		left = t[i][k];
    	}

    	else
    	{
    		left = solve(s , i , k);
    	}

    	if(t[k+1][j] != -1)
    	{
    		right = t[k+1][j];
    	}

    	else
    	{
    		right = solve(s , k+1 , j);
    	}

        temp = left + right + 1;
           
        ans = min(ans , temp);
    }
        
    return t[i][j] = ans;

}

int main()
{
	string s;
	cin >> s;

	//int i = 0;
	int n = s.length();

	memset(t , -1 , sizeof(t));

	cout << solve(s , 0 , n-1) << endl;
	
}