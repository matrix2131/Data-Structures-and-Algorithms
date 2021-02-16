#include<bits/stdc++.h>
using namespace std;

int atoii(char *ch, int n)
{
    if(n == 1)
        return (*ch - '0');
    return (10* atoii(ch,n-1)+ ch[n-1] - '0');
}

int main()
{
    char ch[] = "123456789";
    int n = strlen(ch);
    cout<<atoii(ch,n)<<endl;
}
