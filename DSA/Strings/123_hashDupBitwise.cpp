#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[] = "findings";
    int i,h=0,x=0;
    
    for (i = 0; a[i] != '\0'; i++)
    {
        x=1;
        x=x<<a[i]-97; // shifting
        // cout<< x & h ;
        if((x & h) >0){//masking

            cout<<" duplicate - "<<a[i]<<endl;
        }
        else{
            h=x|h;//merging
        }
    }
    return 0;
}