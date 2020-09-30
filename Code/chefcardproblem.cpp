#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int pc, pr;
        vector<int> pcv, prv;
        cin >> pc >> pr;
        //for pc
        while (pc)
        {
            if (pc > 9)
            {
                pcv.push_back(9);
                pc = pc - 9;
            }
            else
            {
                pcv.push_back(pc);
                pc = pc - pc;
            }
        }
        //for pr
        while (pr)
        {
            if (pr > 9)
            {
                prv.push_back(9);
                pr = pr - 9;
            }
            else
            {
                prv.push_back(pr);
                pr = pr - pr;
            }
        }
        //output
        if (pcv.size() >= prv.size())
            cout << 1 << " " << prv.size() << endl;
        else
            cout << 0 << " " << pcv.size() << endl;
    }
    return 0;
}