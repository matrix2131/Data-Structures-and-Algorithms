#include<bits/stdc++.h>
using namespace std;

void midDel(stack<int> &s, int k)
{
    if(k == 1)
    {
        s.pop();
        return;
    }
    int element = s.top();
    s.pop();
    midDel(s,k-1);
    s.push(element);
}

int main()
{
    int n;
    cin>>n;
    stack<int> s;
    int input;
    for(int i = 0; i<n; i++)
    {
        cin>>input;
        s.push(input);
    }
    int k = s.size()/2 + 1;
    midDel(s,k);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
