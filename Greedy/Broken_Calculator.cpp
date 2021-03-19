#include<bits/stdc++.h>
using namespace std;

// Time Complexity ---> O(n)
// Space Complexity ---> O(1)
int brokenCalc(int X, int Y) {
        int ans = 0;
        
        while(Y > X)
        {
            if(Y%2 == 0)
            {
                Y = Y/2; 
                ans++;
            }
            else
            {
                 Y = Y+1;  
                 ans++;
            }
        }
        return ans+X-Y;
}

int main()
{
    int x1 = 5, y1 = 8;
    int x2 = 3, y2 = 10;
    int x3 = 1024, y3 = 1;
    cout<<brokenCalc(x1,y1)<<endl;
    cout<<brokenCalc(x2,y2)<<endl;
    cout<<brokenCalc(x3,y3)<<endl;
    return 0;
} 
