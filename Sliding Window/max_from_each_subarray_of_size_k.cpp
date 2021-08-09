#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector <int> ans;
        
        if(k > n)
        {
            return ans;
        }
    
        deque <int> d;
        
        int i = 0;
        int j = 0;
        
        while(j < n)
        {
            while(!d.empty() && arr[j] > d.back())
            {
                d.pop_back();
            }
            
            d.push_back(arr[j]);
            
            if(j-i+1 < k)
            {
                j++;
            }
            
            else if(j-i+1 == k)
            {
                ans.push_back(d.front());
                
                if(arr[i] == d.front())
                {
                    d.pop_front();
                }
                
                i++;
                j++;
            }
        }
        
        return ans;
    }

int main()
{
	
}