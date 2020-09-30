// TC : O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={3,4,5,5,6,7,8,8,8,9,10};
    int n = 11;
    int lastDup =0;
    for(int i= 0;i<n-1;i++){
        if(a[i]==a[i+1] && a[i]!=lastDup){
            cout<<a[i]<<endl;
            lastDup =a[i];
        }
    }
    return 0;
}