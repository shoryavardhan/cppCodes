#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 3, 5, 6, 1, 4, 3, 6, 5, 8, 9, 1, 4, 5, 6, 7};
    int n = 16;
    int max = 9;
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