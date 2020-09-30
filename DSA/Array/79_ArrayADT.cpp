#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int len;
};
void Append(struct Array *arr, int x)
{
    if (arr->len < arr->size)
    {
        arr->A[arr->len++] = x;
    }
}
void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->len)
    {
        for (int i = arr->len; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
    }
    arr->A[index] = x;
    arr->len++;
}
void Delete(struct Array *arr, int index)
{
    if (index >= 0 && index <= arr->len)
    {
        for (int i = index; i < arr->len - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
    }
    arr->len--;
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
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    Display(arr);
    Append(&arr, 7);
    Display(arr);
    Insert(&arr, 0, 1);
    Display(arr);
    Delete(&arr, 6);
    Display(arr);
    return 0;
}