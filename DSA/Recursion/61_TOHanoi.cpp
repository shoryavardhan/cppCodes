#include <bits/stdc++.h>
using namespace std;

void TOH(int n, int a, int b, int c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        cout << "Move a disk from tower \"" << a << "\" to tower \"" << c <<"\""<< endl;
        TOH(n - 1, b, a, c);
    }
}
int main()
{
    TOH(3,1,2,3);
}