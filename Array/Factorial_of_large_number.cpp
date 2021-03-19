#include<bits/stdc++.h>
using namespace std;


void factorial(int n)
{
    vector<int> v;
    v.push_back(1);
    for(int i = 2; i<=n; i++)
    {
        int carry = 0;
        for(int j = 0; j<v.size(); j++)     // Here we are multiplying each no. in array by i and store the carry juct like we multiply on paper.
        {
            int m = v[j]*i + carry;
            carry = m / 10;                // The number is stored in reverse array, so we will have to handle carry afterwards carefully.
            v[j] = m % 10;    
        }
        
        while(carry)      // If there is carry at last then it has to be added in front of the number. Here as the number is stored in reverse order, we will have to store carry also in that way.
                          // eg. if we have carry = 10, it will be stored at the end of the vector as 01.
        {
            v.push_back(carry % 10);
            carry = carry/ 10;
        }
    }
    for(int i = v.size()-1; i>=0 ; i--)     // As the answer is in reverse order in array.
    {
        cout<<v[i];
    }
    cout<<endl;
}



int main()
{
    int n;
    cin>>n;
    factorial(n);
}
