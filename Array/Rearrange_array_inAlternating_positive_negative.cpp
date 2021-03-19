#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[], int start, int end)
{
    int temp = arr[end];
    for(int i = end; i>start; i--)
        arr[i] = arr[i-1];
    arr[start] = temp;
}

void solve(int arr[], int n)
{
    int outofplace = -1;
    for(int index = 0; index < n; index++)
    {
        if(outofplace >= 0)
        {
            if((arr[index]<0 && arr[outofplace]>=0) || (arr[index]>= 0 && arr[outofplace]<0))
            {
                rotate(arr,outofplace,index);
                
                if((index-outofplace) >= 2)
                    outofplace += 2;
                else
                    outofplace = -1;
            }
        }
        
        if(outofplace == -1)
        {
            if((arr[index] < 0 && index%2 != 0) || (arr[index] >= 0 && index%2 == 0))
            {
                outofplace = index;
            }
        }
    }
}



int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    solve(arr,n);
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
