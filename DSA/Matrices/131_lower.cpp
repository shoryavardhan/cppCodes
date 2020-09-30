#include <bits/stdc++.h>
using namespace std;

class LowMat
{
private:
    int n;
    int *A;

public:
    LowMat(int n)
    {
        this->n = n;
        A = new int[(n * (n + 1)) / 2];
    }
    void sets(int i, int j, int x)
    {
        // cout << "aaya";
        if (i >= j)
        {
            A[((i * (i + 1)) / 2) + (j - 1)] = x;
        }
        else{
            A[((i * (i + 1)) / 2) + (j - 1)] = 0;
        }
    }
    void get(int i, int j)
    {
        if (i >= j)
        {
            cout << A[(i * (i + 1) / 2) + j - 1] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                {
                    cout << A[(i * (i + 1) / 2) + j - 1] << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
    ~LowMat()
    {
        delete[] A;
    }
};
int main()
{
    int d = 5;
    class LowMat M(d);
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cout << i << "," << j << "   ";
            if (i >= j)
                M.sets(i, j, 1);
        }
        cout << endl;
    }
    M.Display();
    return 0;
}