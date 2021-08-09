#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int lcs(string s1 , string s2)
{
    int x = s1.length();
    int y = s2.length();
        
    int t[x+1][y+1];
       
    for(int i = 0;i<=x;i++)
    {
        for(int j = 0;j<=y;j++)
        {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
        
    for(int i = 1;i<=x;i++)
    {
        for(int j = 1;j<=y;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                t[i][j] = int(s1[i-1]) + t[i-1][j-1];
            }
                
            else
            {
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
      
    return t[x][y];        
}

int solve(string s1, string s2)
{    
    int sum = 0;
     
    for(int i = 0;i<s1.length();i++)
    {
        sum += int(s1[i]);
    }
        
    for(int i = 0;i<s2.length();i++)
    {
        sum += int(s2[i]);
    }
        
    int res = lcs(s1 , s2);
        
    return sum - 2*res;
}


int main()
{
	string a;
	cin >> a;

	string b;
	cin >> b;

	cout << solve(a , b) << endl;
	
}