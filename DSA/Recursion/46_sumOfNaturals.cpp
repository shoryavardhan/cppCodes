#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==0)
    return 0;
    else
    return n + sum(n-1);
}
int main(){
    int x=10;
    cout<<sum(x)<<" ";
    return 0;

}