#include <bits/stdc++.h>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL;

void create(int a[], int n)
{
    struct node *t, *last;
    int i;
    first = new node;
    first->prev = NULL;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void insertAt(struct node *p, int index, int n)
{
    struct node *t;
    int i;
    t = new node;
    t->data = n;
    // chexk for valid index too..
    if (index == 0)
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
void Delete(struct node *p, int index)
{
    struct node *q;
    if (index == 0)
    {
        p = first;
        first = first->next;
        cout << p->data << " deleted" << endl;
        delete (p);
        if (first)
        {
            first->prev = NULL;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        q->next->prev = p;
        cout<<q->data<<" deleted"<<endl;
        delete(q); 
    }
}
void reverse(struct node *p){
    struct node *temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev =temp;
        p=p->prev;
        if(p!=NULL && p->next == NULL)
            first =p;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    display(first);
    insertAt(first, 2, 10);
    display(first);
    Delete(first,2);
    display(first);
    Delete(first, 0);
    display(first);
    reverse(first);
    display(first);
    return 0;
}