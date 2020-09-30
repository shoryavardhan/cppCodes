//with memoisation

#include <bits/stdc++.h>
using namespace std;
int f[10];
int memoisedFib(int n)
{
    if (n == 0 || n == 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 1] == -1)
        {
            f[n - 1] = memoisedFib(n - 1);
        }
        if (f[n - 2] == -1)
        {
            f[n - 2] = memoisedFib(n - 2);
        }
        f[n]= f[n-1]+f[n-2];
        return f[n - 1] + f[n - 2];
    }
}
int recursiveFib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {   
        return recursiveFib(n - 1) + recursiveFib(n - 2);
    }
}
int main()
{
    for(int i=0;i<10;i++){
        f[i] = -1;
    }
    int n = 6;
    cout << recursiveFib(n) << " ";
    cout<< memoisedFib(n)<<" ";
    return 0;
}