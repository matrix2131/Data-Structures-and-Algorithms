#include<bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2)
{
    if(s1.length() != s2.length())
        return false;
        
    string temp = s1 + s1;
    if(temp.find(s2) != string :: npos)
        return true;
}

int main()
{
    string s1, s2;
    cout<<"Enter the 1st string: ";
    cin>>s1;
    cout<<"Enter the second String: ";
    cin>>s2;
    if(solve(s1,s2))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
