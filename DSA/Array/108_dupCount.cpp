#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {3, 4, 5, 5, 6, 7, 8, 8, 8, 9, 10};
    int n = 11;
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            j = i + 1;
            while (a[i] == a[j])
                j++;
            cout << a[i] << " appears " << j - i <<" times."<< endl;
            i=j-1;
        }
    }
    return 0;
}
