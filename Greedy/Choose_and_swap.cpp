#include<bits/stdc++.h>
using namespace std;

string chooseandswap(string a){
    set<char> c;
    
    for(auto it : a)
        c.insert(it);
        
        
    for(int i = 0; i<a.size(); i++)
    {
        c.erase(a[i]);
        if(c.empty())  break;
        
        if(*c.begin() < a[i])
        {
            char l1 = a[i];
            char l2 = *c.begin();
            for(int j = 0; j<a.size(); j++)
            {
                if(a[j] == l1)
                    a[j] = l2;
                else if(a[j] == l2)
                    a[j] = l1;
            }
            break;
        }
        
    }
    return a;
}


int main()
{
    string a = "baab";
    string b = "soniya";
    cout<<chooseandswap(a)<<endl;
    cout<<chooseandswap(b)<<endl;
    return 0;
}
