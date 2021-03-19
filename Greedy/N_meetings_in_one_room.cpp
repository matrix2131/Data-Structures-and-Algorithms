#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N*logN)
// Space Complexity ---> O(N)

int maxMeetings(int start[], int end[], int n) {
    int ans = 0;
    int last = 0;
    multimap<int, int> m;
    
    for(int i = 0; i<n; i++)
    {
        m.insert(pair<int,int> (end[i],start[i]));
    }
    
    for(auto it : m)
    {
        if(it.second > last)
        {
            ans++;
            last = it.first;
        }
    }
    return ans;
}


int main()
{
    int n1 = 6;
    int start1[] = {1,3,0,5,8,5};
    int end1[] = {2,4,6,7,9,9};
    cout<<maxMeetings(start1, end1, n1)<<endl;
    
     int n2 = 8;
    int start2[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
    int end2[] = {112960, 114515, 81825, 93424, 54316,35533, 73383, 160252};
    cout<<maxMeetings(start2, end2, n2)<<endl;
    return 0;
    
}
