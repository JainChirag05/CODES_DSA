#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string solve(string s, string t) 
{
    int i=0,j=0,ans=INT_MAX,start=0;

    unordered_map<char,int> mp;
    
    for(int i = 0;i<t.length();i++)
    {
    	mp[t[i]]++;
    }
    
    int count=mp.size();
        
    if(mp.find(s[j]) != mp.end())
    {
    	mp[s[j]]--;
        
        if(mp[s[j]]==0)
        {
			count--;
        }
    }
        
    while(j<s.length())
    {
        if(count>0)
        {
            j++;
        	
        	if(mp.find(s[j])!=mp.end())
        	{
                mp[s[j]]--;
                
                if(mp[s[j]]==0)
                {
                	count--;
                }
            }
        }

        else if(count==0)
        {
            if(ans>j-i+1)
            {
                ans = j-i+1;
                start=i;
            }
            
            while(count==0)
            {
                if(mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    
                    if(mp[s[i]]==1)
                    {
                        count++;
                        
                        if(ans>j-i+1)
                        {
                            ans=j-i+1;
                            start=i;
                        } 
                    }
                    
                    i++;
                }
                
                else
                {
                	i++;
                }
            }
        }
    }
    
    string str="";
    
    if(ans!=INT_MAX)
    {
    	return str.append(s.substr(start,ans));
    }
    
    else
    {
    	return str;
    }
}

int main()
{
	string s;
	cin >> s;

	string t;
	cin >> t;

	cout << solve(s , t);
	
}