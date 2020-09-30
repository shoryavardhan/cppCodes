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

node *revPair(node *head){
    node * temp = head;
    if(head!=NULL|| head->next !=NULL){
        swap(head->data,head->next->data);
        revPair(head->next->next);
    }    
    return head;
}
int main(){
    node *head= NULL;
    node *revHead;
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    // head = insert(head,6);
    cout<<"Original:";
    node *temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
    revHead = revPair(head);
    cout<<"Reverse:";
    while(revHead){
        cout<<revHead->data<<" ";
        revHead= revHead->next;
    }
    cout<<endl;
    return 0;
}