#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int arr[], int N, int X)
{
    sort(arr, arr+N);
    {
        for(int i = N-1; i>=1; i--)
        {
            int l = 0,r = i-1;
            while(l<r)
            {
                if(arr[i]+arr[l]+arr[r] == X)
                    return 1;
                if(arr[i]+arr[l]+arr[r] < X)
                    l++;
                else
                    r--;
            }
        }
    }
}

int main()
{
	int n,x;
	cout<<"Enter Size of array: ";
	cin>>n;
	cout<<"Enter elements of array: ";
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the required sum: ";
	cin>>x;

	if(find3Numbers(arr,n,x))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
}
	
