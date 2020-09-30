2#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data){
    Node* node= new Node();
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
void inorder(Node* root){
     if (root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int isMirror(Node* a,Node* b){
    if (a==NULL && b==NULL) 
        return true; 

    if (a==NULL || b == NULL) 
        return false; 
    return  a->data == b->data && 
            isMirror(a->left, b->right) && 
            isMirror(a->right, b->left);

}


int main(){
    Node* root=newNode(1);
    root->left=newNode(3);
    root->right=newNode(2);
    root->right->left=newNode(5);
    root->right->right=newNode(4);
    Node* root2=newNode(1);
    root2->left=newNode(2);
    root2->left->left=newNode(4);
    root2->left->right=newNode(5);
    root2->right=newNode(3);
    cout<<"Normal : ";
    inorder(root); 
    cout<<endl;
    cout<<"Mirror : ";
    inorder(root2); 
    cout<<endl;
    int c=isMirror(root,root2);
    if(c==1){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}
