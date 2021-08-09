#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool valid(vector<vector<int>> &arr , int x , int y , int n)
{
    int row = x;
    int col = y;
	    
    while(row >= 0 && col>= 0)
    {
        if(arr[row][col] == 1)
        {
            return false;
        }
	        
        row--;
        col--;
    }
	    
    row = x;
    col = y;
    
    while(row >= 0 && col < n)
    {
        if(arr[row][col] == 1)
        {
            return false;
        }
	        
        row--;
        col++;
    }
    
    row = x;
    col = y;
	    
    while(row >= 0)
    {
        if(arr[row][col] == 1)
        {
            return false;
        }
	        
        row--;
    }
    
    return true;
}
    
void final(vector<vector<int>> &arr , int x , int n , vector<vector<int>> &sol)
{
    if(x == n)
    {
	    vector<int> temp;
	   
        for(int i = 0;i<n;i++)
		{
		    for(int j = 0;j<n;j++)
		    {
		        if(arr[i][j] == 1)
		        {
		           temp.push_back(j+1); // Adding position
		        }
		    }
		}
		   
		sol.push_back(temp);

		return;
	}

	for(int j = 0;j < n;j++)
	{
	    if(valid(arr ,x , j , n))
	    {
		    arr[x][j] = 1;

		    final(arr , x+1 , n , sol);

		    arr[x][j] = 0;
	    }
	}
}
    
vector<vector<int>> solve(int n) 
{
    vector<vector<int>> arr(n , vector<int>(n,0)) , sol;
       
    final(arr , 0 , n , sol);
        
    return sol;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> ans = solve(n);

	for(int i = 0;i<ans.size();i++)
	{
		for(int j = 0;j<ans[0].size();j++)
		{
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}
}