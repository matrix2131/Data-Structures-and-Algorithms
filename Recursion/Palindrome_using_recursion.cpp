#include<bits/stdc++.h>
using namespace std;

void palindrome(string str, int f, int l)
{
    if(f == l)
    {
	cout<<"YES"<<endl; 
        return;
    }
    if(f > l)
    {
        cout<<"YES"<<endl; 
        return;
    }
    if(str[f] != str[l])
    {
        cout<<"NO"<<endl; 
        return;
    }
    palindrome(str, f+1, l-1);
}

int main()
{
    string str;
    cin>>str;
    int n = str.size();
    int f = 0, l = n-1;
    palindrome(str,f,l);
}
