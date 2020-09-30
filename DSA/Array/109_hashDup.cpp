#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {3, 4, 5, 5, 6, 7, 8, 8, 8, 9, 10};
    int n = 11;
    int max = 10;
    int hash[max] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    for (int i = 0; i < max; i++)
    {
        if (hash[i] > 1)
        {
            cout << i << " appears " << hash[i] << " times." << endl;
        }
    }
    return 0;
}