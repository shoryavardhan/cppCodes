#include <bits/stdc++.h>
using namespace std;

int t;
int main()
{
    cin >> t;
    while (t--)
    {
        //inputs
        int n, k, ans =INT_MAX, res = -1;
        cin >> n >> k;
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        //calculated array construction
        for (int i = 0; i < n; i++)
            if (k % p[i] == 0)
                p[i] = (k / p[i]);
            else
                p[i] = 0;
        //minimum value of steps calculation
        for (int i = 0; i < n; i++)
        {
            if (p[i] < ans && p[i] != 0)
            {
                ans = p[i];
                res = i;
            }
        }
        //final ans calculation
        //output
        if (res == -1)
            cout << res << endl;
        else
        {
            res = k / p[res];
            cout << res << endl;
        }
    }
    return 0;
}
