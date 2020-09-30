#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p, h, i;
        cin >> h >> p;
        while(h>0){
            h=h-p;
            p=p/2;
            if(p>h){
                cout<<1<<endl;
                break;
            }
            else if(p==0 &&h!=0){
                cout<<0<<endl;
                break;
            }
            else if(p==0 && h==0){
                cout<<1<<endl;
                break;
            }
            cout<<h<<" "<<p<<endl;    
            }}
    return 0;
}