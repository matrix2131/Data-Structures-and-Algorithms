#include<bits/stdc++.h>
using namespace std;

// Time complexity ----> O(n*n*log(k))
// space complexity ----> O(k)

int solve(int arr[],int n, int k)
{
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> minh;
    for(int i = 0; i<n; i++)
    {
        sum = arr[i];
        minh.push(sum);
        if(minh.size()>k)
            minh.pop();
        for(int j = i+1; j<n; j++)
        {
            sum += arr[j];
            minh.push(sum);
            if(minh.size() > k)
            {
                minh.pop();
            }
        }
    }
    return minh.top();
}


int main()
{
    int arr[] = {10, -10, 20, -40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    cout<<solve(arr,n,k)<<endl;
}
