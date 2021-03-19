#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N)
// Space Complexity ---> O(1)

int smallestSubWithSum(int arr[], int n, int x)
{
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        int curr_sum = 0;
        int len = n+1;
        
        int end = 0, start = 0;
        
        while(end < n)
        {
            while(curr_sum <= x && end < n)
                curr_sum += arr[end++];
                
            while(curr_sum > x && start < n)
            {
                if(end-start < len)
                    len = end - start;
                
                curr_sum -= arr[start++];
            }
                
            
        }
        return len;
    }
}

int main()
{
    int arr1[] = { 1, 4, 45, 6, 10, 19 };
    int x = 51;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1 + 1) ? cout << "Not possible\n": cout << res1 << endl;
 
    int arr2[] = { 1, 10, 5, 2, 7 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    x = 9;
    int res2 = smallestSubWithSum(arr2, n2, x);
    (res2 == n2 + 1) ? cout << "Not possible\n": cout << res2 << endl;
 
    int arr3[] = { 1, 11, 100, 1, 0, 200, 3, 2, 1, 250 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    x = 280;
    int res3 = smallestSubWithSum(arr3, n3, x);
    (res3 == n3 + 1) ? cout << "Not possible\n": cout << res3 << endl;
    
}
