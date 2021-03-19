#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N^2)
// Space Complexity ---> O(N)


struct Job{
    int id;
    int dead;
    int profit;
};


bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> v;
        int gain = 0, job = 0;
        sort(arr,arr+n, comparison);
        
        int slot[n];
        int r[n];
        for(int i = 0; i<n; i++)
        {
            slot[i] = false;
        }
        
        for(int i =0; i<n; i++)
        {
            for(int j = min(n,arr[i].dead)-1; j>=0; j--)
            {
                if(slot[j] == false)
                {
                    slot[j] = true;
                    gain += arr[i].profit;
                    job++;
                    break;
                }
            }
        }
        v.push_back(job);
        v.push_back(gain);
        
        return v;
    }  


int main()
{
    int n;
    cin>>n;
    
    Job arr[n];
    for(int i = 0; i<n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    
    vector<int> ans = JobScheduling(arr,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
    
}
