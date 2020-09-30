#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
Node *insert(Node *head, int d){
    Node *newNode  = new Node;
    newNode->data=d;
    newNode->next = NULL;
    Node *cur = head;
    if(head == NULL){
        head= newNode;
    }
    else{
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=newNode;
        cur=cur->next;
    }
    return head;
}
void print(Node *head){
    while(head){
        cout<<head->data<<"| -> |";
        head=head->next;
    }
}
int main(){
    Node *head =NULL;
    for(int i=0;i<10;i++){
        head = insert(head,i);
    }
    cout<<"|";
    print(head);
    cout<<"NULL|"<<endl;
    return 0;
}
