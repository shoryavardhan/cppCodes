// two cars will meet each other on circular track if one of them is faster
// and will never meet on a linear track

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct node *t, *last;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
int checkLoop(struct node *p)
{
    struct node *car1, *car2;
    car1 = car2 = p;
    do
    {
        car1 = car1->next;
        car2 = car2->next;
        car2 = car2 ? car2->next : car2;
    } while (car1 && car2 && car1 != car2);
    if (car1 == car2) // cars meet hence circular
        return 1;
    else
        return 0; // dont meet despite speed differnece hence linear
}
int main()
{
    struct node *t1, *t2;
    int A[] = {10, 40, 50, 70, 90};
    create(A, 5);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    cout << checkLoop(first) << endl;
    return 0;
}
