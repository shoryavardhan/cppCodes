#include <bits/stdc++.h>
using namespace std;

int c(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return c(n - 1, r - 1) + c(n - 1, r);
    }
}
int main()
{

    cout << "    "<< c(0, 0) << endl;
    cout << "   " << c(1, 0) << " " << c(1, 1) << endl;
    cout << "  "<< c(2, 0) << " " << c(2, 1) << " " << c(2, 2) << endl;
    cout << " "<< c(3, 0) << " " << c(3, 1) << " " << c(3, 2) << " " << c(3, 3) << endl;
    cout << c(4, 0) << " " << c(4, 1) << " " << c(4, 2) << " " << c(4, 3) << " " << c(4, 4) << endl;
}