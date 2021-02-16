#include<bits/stdc++.h>
using namespace std;

void printString(string str, int start, int end)
{
    for(int i = start; i<=end; i++)
    {
        cout<<str[i];
    }
    cout<<endl;
}


string LongestPalindrome(string str)
{
    int l,h;
    int start = 0, end = 1;
    for(int i = 1; i<str.length(); i++)
    {
        // even substring
        l = i-1;
        h = i;
        
        while(l >= 0 && h < str.length() && str[l] == str[h])
        {
            if((h-l+1) > end)
            {
                start = l;
                end = h-l+1;
            }
            
            l--;
            h++;
        }
        
        
        // odd substring
        l = i-1;
        h = i+1;
        
        while(l >= 0 && h < str.length() && str[l] == str[h])
        {
            if((h-l+1) > end)
            {
                start = l;
                end = h-l+1;
            }
            
            l--;
            h++;
        }
    }
    printString(str,start, start + end-1);
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        LongestPalindrome(s);
    }
}
