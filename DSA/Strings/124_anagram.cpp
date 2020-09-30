#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[] = "aaasok";
    char b[] = "kaaaso";
    int hash[25] = {0};
    for (int i = 0; i < 7; i++)
    {
        hash[a[i] - 97]++;
    }
    for (int i = 0; i < 7; i++)
    {
        hash[b[i] - 97]--;
    }
    for (int i = 0; i < 25; i++)
    {
        cout << hash[i] << " ";
    }

    for (int i = 0; i < 25; i++)
    {
        if (hash[i] != 0)
        {
            cout << endl
                 << "Not a anagram" << endl;
            return 0;
        }
    }
    cout << "Anagram" << endl;
    return 0;
}