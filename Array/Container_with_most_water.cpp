#include<bits/stdc++.h>
using namespace std;

// Time Complexity ---> O(n) [as only one traversal of array is done]
// Space Complexity -----> O(1)

int solve(int arr[], int n)
{
    int ans = 0;
    int l = 0, r = n-1;
    while(l<r)
    {
        ans = max(ans, min(arr[l],arr[r])*(r-l));
        if(arr[l] > arr[r])
            r--;
        else
            l++;
    }
    return ans;
}

int main()
{
    int arr[] = {3, 1, 2, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,n);
    return 0;
}
