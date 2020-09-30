// pairs that make sume k
// TC : O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {6, 3, 4, 8, 10, 16, 7, 5, 2, 14};
    int n = 10;
    int max = 16;
    int k = 10;
    int hash[max] = {0};
    for (int i = 0; i < n; i++)
    {
        if (hash[k - a[i]] == 1)
            cout << "pair exists : " << a[i] << " & " << k - a[i] << endl;
        hash[a[i]]++;
    }
    return 0;
}