// check positive negative and if the array is sorted also insert a num in a sorted array. also merging two arrays
#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int len;
};
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void insertSorted(struct Array *arr, int x)
{
    int i = arr->len - 1;
    if (arr->len >= arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->len++;
}

bool isSorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.len - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}
void posNeg(struct Array *arr)
{
    int i = 0, j = arr->len - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] > 0)
            j--;
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}
struct Array *merge(struct Array a, struct Array b)
{
    int length = a.len + b.len;
    struct Array *c = new struct Array;
    int i = 0, j = 0, k = 0;
    while (i < a.len && j < b.len)
    {
        if (a.A[i] < b.A[j])
            c->A[k++] = a.A[i++];
        else if (a.A[i] > b.A[j])
            c->A[k++] = b.A[j++];
    }
    for (; i < a.len; i++)
        c->A[k++] = a.A[i];

    for (; j < b.len; j++)
        c->A[k++] = b.A[j];
    c->len=length;
    return c;
}
void Display(struct Array arr)
{
    int i;
    cout << "\nElements are" << endl;
    for (i = 0; i < arr.len; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}
int main()
{
    struct Array arr = {{2, 4, 6, 10}, 20, 4};
    struct Array arr2 = {{2, -3, 4, -5, 6, -7, 9, -10}, 20, 8};
    struct Array arr3 = {{1, 3, 5, 7, 9}, 20, 5};
    insertSorted(&arr, 8);
    Display(arr);
    posNeg(&arr2);
    Display(arr2);
    struct Array *arr4 = new struct Array;
    arr4=merge(arr,arr3);
    Display(*arr4);

    return 0;
}