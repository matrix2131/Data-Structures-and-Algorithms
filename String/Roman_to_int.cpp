#include<bits/stdc++.h>
using namespace std;

// Time complexity ---> O(n)

int romanToInt(string s) {
        int ans = 0;
        s += '@';
        map<char,int> m{                   //O(logn)
            {'I' , 1}, 
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000},
            {'@' , 0}
        };
        
        for(int i = 0; i<s.size()-1; i++)
        {
            if(m[s[i]] < m[s[i+1]])
            {
                ans += m[s[i+1]] - m[s[i]];
                i++;
            }
            else
            {
                ans += m[s[i]];
            }
        }
    return ans;
}

int main()
{
    string s1 = "III";
    string s2 = "XL";
    string s3 = "MCMXCIV";
    cout<<s1<<" : "<<romanToInt(s1)<<endl;
    cout<<s2<<" : "<<romanToInt(s2)<<endl;
    cout<<s3<<" : "<<romanToInt(s3)<<endl;
    return 0;
}
