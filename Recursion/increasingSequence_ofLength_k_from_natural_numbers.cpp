#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int k)
{
    for(int i = 0; i<k; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve(int arr[], int n, int k, int len)
{
    if(len == k)
    {
        printArray(arr,k);
        return;
    }
    
    int i = (len == 0) ? 1 : arr[len-1] + 1;
    len++;
    
    while(i <= n)
    {
        arr[len-1] = i;
        solve(arr,n,k,len);
        i++;
    }
    
    len--;
}

int main()
{
    int k,n;
    cin>>k>>n;
    int arr[k];
    int len = 0;
    solve(arr,n,k,len);
}
