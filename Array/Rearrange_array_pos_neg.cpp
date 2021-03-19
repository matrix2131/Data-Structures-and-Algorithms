#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
	int neg = 0;
	for(int i = 0; i<n; i++)
	{
		if(arr[i] < 0)
		{
			swap(arr[neg],arr[i]);
			neg += 2;
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

	rearrange(arr,n);
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
}

