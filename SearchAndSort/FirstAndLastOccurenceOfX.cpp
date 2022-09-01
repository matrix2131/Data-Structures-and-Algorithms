#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(logn)

int search(int arr[], int n, int x)
{
    int l = 0, h = n,m;
    while(l <= h)
    {
        m = l+((h-l)/2);
        if(arr[m] == x)
            return m;
        else if(arr[m] > x)
            h = m-1;
        else
            l = m+1;
    }
    return -1;
}

vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    int pos = search(arr, n,x);
    if(pos == -1)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    int i = pos, j = pos;
    while(i>=0)
    {
        if(arr[i] == x)
            i--;
        else
            break;
    }
    while(j<n)
    {
        if(arr[j] == x)
            j++;
        else
            break;
    }
    ans.push_back(i+1);
    ans.push_back(j-1);
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n], i;
        for(i = 0; i<n; i++)
            cin>>arr[i];
        vector<int> ans;
        ans = find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}