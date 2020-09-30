#include <bits/stdc++.h>
using namespace std;
void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void permutation(char str[], int l, int h)
{
    int i;
    if (l == h)
        cout << str << endl;
    else
        for (i = l; l <= h; i++)
        {
            swap(&str[l], &str[i]);
            permutation(str, l + 1, h);
            swap(&str[l], &str[i]);
        }
}
int main()
{
    char str[] = "abc";
    permutation(str, 0, 2);
    return 0;
}