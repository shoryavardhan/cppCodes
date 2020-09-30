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

node *merge(node *head,node *head2, int f){
    node *cur= head;
    node *cur2= head2;
    node *newLL = NULL;
    node *temp1;
    node *temp2;
    //f=0 for ll1
    //f=1 for ll2
    while(cur!=NULL || cur2!=NULL){
        if(f==0){
            cur =  merge(cur->next,cur2, 1);
        }
        else if(f==1){
            cur =  merge(cur,cur2->next, 0);
        }
        

    }
    return cur;
}

int main(){
    node *head= NULL;
    node *head2 = NULL;
    int f= 0;
    for(int i= 1;i<=5;i++){
    head = insert(head,i);
    }
    for(int i= 6;i<=10;i++){
    head2 = insert(head2,i);
    }
    cout<<"Original 1:";
    node *temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
    cout<<"Original 2:";
    temp= head2;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
    node *merged = merge(head,head2,f);
    cout<<"Merged:";
    temp= merged;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
    return 0;
}