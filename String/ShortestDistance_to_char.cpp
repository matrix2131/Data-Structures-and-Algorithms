#include<bits/stdc++.h>
using namespace std;

vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        
        int occur = INT_MAX;
        
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == c)
                occur = i;
            if(occur == INT_MAX)
                ans.push_back(INT_MAX);
            else
                ans.push_back(abs(i - occur));
        }
        
        occur = INT_MAX;
        for(int i = s.length()-1; i>=0; i--)
        {
            if(s[i] == c)
                occur = i;
            if(occur != INT_MAX)
                ans[i] = min(ans[i], occur-i);
        }
        return ans;
}

int main()
{
    vector<int> a;
    cout<<"String: ";
    string s;
    cin>>s;
    cout<<"Character: ";
    char c;
    cin>>c;
    a = shortestToChar(s,c);
    for(auto i : a)
        cout<<i<<" ";
}
