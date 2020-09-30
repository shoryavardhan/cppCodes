#include <bits/stdc++.h>
using namespace std;

void permutation(char str[], int k)
{

    static int avail[10] = {0};
    static int count =0;
    static char res[10];
    int i;
    if (str[k] == '\0')
    {
        res[k] = '\0';
        count++;
        cout <<"No. "<<count<<"  "<< res << endl;
    }
    else
        for (i = 0; str[i] != 0; i++)
            if (avail[i] == 0)
            {
                res[k] = str[i];
                avail[i] = 1; // mtlb char ab available nho bacha
                permutation(str, k + 1);
                avail[i] = 0; //char wapis available ho gya
            }
}
int main()
{
    char str[] = "abc";
    permutation(str, 0);
    return 0;
}