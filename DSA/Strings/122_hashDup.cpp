#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[] = "findings";
    int hash[26]={0};
    int i;
    for(i=0;a[i]!='\0';i++){
        hash[a[i]-97]++;
    }
    for(i =0;i<26;i++){
        if(hash[i]>1){
            cout<<char(i+97)<<endl;
        }
    }
    return 0;
}