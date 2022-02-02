#include<bits/stdc++.h>
using namespace std;

// Time Complexity ----> O(n)
// Space Complexity ----> O(n)  (as stack can fill max upto n if all are '(' in the given string)

string minRemoveToMakeValid(string s) {
        string a="";
        stack<int> st;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            
            if(s[i] == ')')
            {
                if(!st.empty())
                    st.pop();
                else
                    s[i] = '@';
            }   
        }
        
        while(!st.empty())
        {
            s[st.top()] = '@';
            st.pop();
        }
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != '@')
                a += s[i];
        }
        return a;
    }

int main()
{
   string s1 = "lee(t(c)o)de)";
   string s2 = "))((";     // Output should be empty string.
   string s3 = "(a(b(c)d)";
   cout<<minRemoveToMakeValid(s1)<<endl;
   cout<<minRemoveToMakeValid(s2)<<endl;
   cout<<minRemoveToMakeValid(s3)<<endl;
   return 0;
}
