#include <bits/stdc++.h>
using namespace std;

// all functions in this program ---->
void create(int A[], int n);                     // takes an array and creates a linked list
void insert(struct node *p, int data);           // insert a node at end
void insertAt(struct node *p, int index, int x); // insert a node at a given location
void insertSorted(struct node *p, int x);        // insert a node at aoptimal location in a sorted list
int count(struct node *p);                       // count nodes
int search(struct node *p, int key);             // find some node
int max(struct node *p);                         // find max node
int sum(struct node *p);                         // find sum of all nodes
void display(struct node *p);                    // display the linked list
int Delete(int pos);                             // delete at defined position
void remDup(struct node *p);                     // remove duplicates if any
void reverseLinks(struct node *p);               // reverse linked list by reversing its links using three sliding pointers
void reverseLinksRecur(struct node *p);          // reverse linked list by recursion
void concat(struct node *p, struct node *q);     // concatenate two linked lists
void merge(struct node *p, struct node *q);      // merge two linked list

struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL, *fourth = NULL;

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
void create2(int A[], int n)
{
    int i;
    struct node *t, *last;
    second = new node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void insert(struct node *p, int data)
{
    struct node *t = new node;
    t->data = data;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p->next)
        {
            p = p->next;
        }
        p->next = t;
        p = t;
    }
    cout << endl
         << "inserted " << data;
}
int count(struct node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
void insertAt(struct node *p, int index, int x)
{
    struct node *t;
    int i;

    if (index < 0 || index > count(p))
        return;
    t = new node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
    cout << endl
         << "inserted " << x << " at " << index;
}
void insertSorted(struct node *p, int x)
{
    struct node *q = NULL, *t;
    t = new node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
    cout << endl
         << "inserted " << x << " in sorted list";
}
int search(struct node *p, int key)
{
    int found = -1;
    int count = 0;
    while (p)
    {
        count++;
        if (p->data == key)
        {
            found++;
            return count;
        }
        p = p->next;
    }
    if (found != -1)
        return count;
    else
        return 0;
}
int max(struct node *p)
{
    int max = -32763;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int sum(struct node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
void display(struct node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int Delete(int pos)
{
    struct node *p, *q;
    int x = -1, i;
    if (pos == 1)
    {
        x = first->data;
        p = first;
        first = first->next;
        delete (p);
    }
    else
    {
        p = first;
        q = NULL;
        while (pos - 1 && p)
        {
            q = p;
            p = p->next;
            pos--;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            delete (p);
        }
    }
    return x;
}
void remDup(struct node *p)
{
    struct node *q;
    q = p->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
    cout << "Removed Duplicates" << endl;
}
void reverseLinks(struct node *p)
{
    struct node *q, *r;
    q = r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
    cout << "reversed" << endl;
}
void reverseLinksRecur(struct node *q, struct node *p)
{
    if (p)
    {
        reverseLinksRecur(p, p->next);
        p->next = q; //returning time
    }
    else
    {
        first = q; // at last make it first (just before returning)
    }
    // cout << "reversed" << endl;
}
void concat(struct node *p, struct node *q)
{
    third = p;
    while (p->next)
        p = p->next;
    p->next = q;
    cout << "concatenated" << endl;
}
void Merge(struct node *p, struct node *q)
{
    struct node *last;
    if (p->data < q->data)
    {
        fourth = last = p;
        p = p->next;
        fourth->next = NULL;
    }
    else
    {
        fourth = last = q;
        q = q->next;
        fourth->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int main()
{
    int A[] = {10, 40, 50, 70, 90};
    int B[] = {21, 30, 80};
    cout << "********************************************************************************************" << endl;
    create(A, 5);
    create2(B, 3);
    display(first);
    insert(first, 100); //this simply inserts at last.
    cout << endl;
    display(first);
    int key = 35;
    int f = search(first, key);
    cout << endl
         << "The sum of total " << count(first) << " elements is " << sum(first) << " and the max element is " << max(first) << " and \'" << key << ((f == 0) ? "\' was never found" : "\' is found ");
    insertAt(first, 1, 20); //this inserts at given location.
    insertSorted(first, 50);
    insertSorted(first, 60); // this inserts at the optimal loaction
    insertSorted(first, 90);
    cout << endl;
    display(first);
    f = search(first, key);
    cout << endl
         << "The sum of total " << count(first) << " elements is " << sum(first) << " and the max element is " << max(first) << " and \'" << key << ((f == 0) ? "\' was never found" : "\' is found ") << endl;
    cout << "Deleted " << Delete(7) << endl;
    display(first);
    cout << endl;
    remDup(first);
    display(first);
    cout << endl;
    reverseLinks(first);
    display(first);
    cout << endl;
    reverseLinksRecur(NULL, first);
    display(first);
    cout << endl;
    
    // Apparently merge and concatenate functions are not working finr together.

    Merge(first, second);
    display(fourth);
    cout << endl;
    concat(first, second);        
    display(third);
    cout << endl;

    cout << "********************************************************************************************" << endl;
    return 0;
}
