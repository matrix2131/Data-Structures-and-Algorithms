#include<bits/stdc++.h>
using namespace std;

int countingValleys(int steps, string path) {
    int ans = 0,s = 0,u = 0,d = 0;
    for(int i = 0; i<steps; i++)
    {
        if(path[i] == 'U')
            u++;
        if(path[i] == 'D')
            d++;
        if(u > d)
            s = 1;
        if(u < d)
            s = -1;
        if(u == d)
        {
            if(s == -1)
                ans++;
        }
    }
    return ans;
}

int main()
{
    int steps1 = 8;
    string path1 = "UDDDUDUU";
    cout<<countingValleys(steps1,path1)<<endl;
    
    int steps2 = 12;
    string path2 = "DDUUDDUDUUUD";
    cout<<countingValleys(steps2,path2)<<endl;
}