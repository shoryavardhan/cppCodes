// array: 6  7  8 10 11 13 14
// index: 0  1  2  3  4  5  6  
//       _____________________
// diff:  6  6  6  7  7  8  8  <-- diff remains 6 until no missing element is found but increases by 1 for every missing element.

// Time Complexcity : O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7, 10, 11, 12};
    int l = arr[0], n = 9;
    int diff = l;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
    return 0;
}