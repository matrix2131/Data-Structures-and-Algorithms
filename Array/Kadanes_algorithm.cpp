#include<bits/stdc++.h>
using namespace std;

int maxSubArray_sum(int arr[], int n)
{
    int local_max = 0;
    int global_max = INT_MIN;
    for(int i = 0; i<n; i++)
    {
        local_max = max(arr[i], arr[i]+local_max);
        if(local_max > global_max)
        {
            global_max = local_max;
        }
    }
    return global_max;
}

int main()
{
    int arr[] = {1,2,-3,4,5,-6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum sum is: "<<maxSubArray_sum(arr,n)<<endl;
}