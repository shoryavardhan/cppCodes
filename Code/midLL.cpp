#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};
node *insert(node *head,int data ){
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    node *cur = head;
    if(head==NULL){
        head = temp;
    }
    else{
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=temp;
    }
    return head;
}

int midLL(node *head){
    node *d;
    node *s;
    d=head;
    s =head;
    int count = 0;
    while(d && d->next && d->next->next){
        s = s -> next;
        d = d -> next -> next;
        count++;
    }
    // cout<<count;
    return s->data;
}
int main(){
    node *head= NULL;
    int mid;
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    head = insert(head,6);
    head = insert(head,7);
    head = insert(head,8);
    head = insert(head,9);
    head = insert(head,10);
    head = insert(head,11);
    cout<<"Original:";
    node *temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
    mid = midLL(head);
    cout<<"Middle:";
    cout<<mid<<endl;
    return 0;
}