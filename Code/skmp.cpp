#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

int compare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}
void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
int *getCount(char *str)
{
    int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for (i = 0; *(str + i); i++)
        count[*(str + i)]++;
    return count;
}
char *removeChars(char *str, char *p)
{
    int *count = getCount(p);
    int ip_ind = 0, res_ind = 0;
    while (*(str + ip_ind))
    {
        char temp = *(str + ip_ind);
        if (count[temp] == 0)
        {
            *(str + res_ind) = *(str + ip_ind);
            res_ind++;
        }
        ip_ind++;
    }
    *(str + res_ind) = '\0';

    return str;
}
char *printStr(){

}
int main()
{
    char str[100000];
    char p[100000];
    cin >> str >> p;
    int c = 0;
    int size = strlen(str);
    qsort(str, size, sizeof(str[0]), compare);
    char str2[100];
    printStr(removeChars(str, p));
    cout<<str2;

    return 0;
}
