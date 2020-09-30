#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        st->top++;
        st->s[st->top] = x;
        cout << "Pushed " << x << endl;
    }
}
void pop(struct Stack *st)
{
    if (st->top == -1)
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "Popped " << st->s[st->top] << endl;
        st->top--;
    }
}
void peek(struct Stack st, int pos){
    if((st.top)-pos+1 < 0)
        cout<<"Invalid Position "<<endl;
    else{
        cout<<"Value at "<<pos<<" is "<<st.s[(st.top)-pos+1]<<endl;
    }
}
void create(struct Stack *st){
    cout<<"Enter Size ";
    cin>>st->size;
    st->s= new int[st->size];
    st->top=-1;
}
void Display(struct Stack st){
    int i;
    for(i=st.top;i>=0;i--){
        cout<<st.s[i]<<endl;
    }
    cout<<endl;
}
int main()
{
    struct Stack st;
    create(&st);
    push(&st, 5);
    push(&st, 15);
    push(&st, 25);
    push(&st, 35);
    push(&st, 45);
    push(&st, 55);
    Display(st);
    pop(&st);
    Display(st);
    peek(st,2);
    return 0;
}