#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	bool ispar(string s)
    {
        char x;
        
        stack <char> st;
        int n = s.length();
        
        for(int i = 0;i<n;i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
                continue;
            }
            
            if(st.empty())
            {
                return false;
            }
            
            switch(s[i])
            {
                case ')':
                
                x = st.top();
                st.pop();
                
                if(x != '(')
                {
                    return false;
                }
                    
                break;
                    
                case '}':
                
                x = st.top();
                st.pop();
                    
                if(x != '{')
                {
                    return false;
                }
                    
                break;
                    
                case ']':
                    
                x = st.top();
                st.pop();
                
                if(x != '[')
                {
                    return false;
                }
                    
                break;
                    
            }
            
        }
        
        if(st.empty())
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
}
