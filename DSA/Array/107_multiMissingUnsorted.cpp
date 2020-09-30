// TC : O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={3,2,1,6,7,5,4,12,10,11};
    int low =1;
    int max= 12;
    int n= 10;
    int hash[max]={0};
    for(int i=0;i<10;i++){
        hash[a[i]]=1;
    }
    for(int i= low;i<max;i++){
        if(hash[i]==0){
            cout<<i<<endl;
        }
    }
    return 0;
}