#include <bits/stdc++.h>
using namespace std;

class DiagMat
{
private:
    int n;
    int *A;

public:
    DiagMat(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void sets(int i, int j, int x)
    {
        if(i==j){
            A[i-1] =x;
        }

    }
    void get(int i, int j){
        if(i==j){
            cout<< A[i-1]<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    void Display(){
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    cout<<A[i - 1]<<" ";
                }
                else
                {
                   cout<< 0<<" ";
                }
            }
            cout<<endl;
        }
    }
    ~DiagMat()
    {
        delete[] A;
    }
};
int main()
{
    class DiagMat M(6);
    M.sets(1, 1, 1);
    M.sets(2, 2, 2);
    M.sets(3, 3, 3);
    M.sets(4, 4, 4);
    M.sets(5, 5, 5);
    M.sets(6, 6, 6);
    M.get(3, 3);
    M.get(4, 5);
    M.Display();

    return 0;
}