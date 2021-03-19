#include<bits/stdc++.h>
using namespace std;

// Time complexity ---> O(n)

int main()
{
    string s = "0100110101";
    int zeros = 0, ones = 0, count = 0;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] == '0')
            zeros++;
        if(s[i] == '1')
            ones++;
        if(ones == zeros)
            count++;
    }
    
    if(zeros != ones)
        cout<<-1<<endl;
    else
        cout<<count<<endl;
}
