// pairs that make sume k
// TC : O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 16};
    int n = 10;
    int k = 10;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == k)
            cout << "pair " << a[i++] << " & " << a[j--]<<endl;
        else if (a[i] + a[j] > k)
            j--;
        else
            i++;
    }
    return 0;
}