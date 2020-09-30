// This is the recursive method there is a iterative method to solve this problem too
// which uses the queue based level order traversal(BFS) and while traversing it swaps
// the left and right children of every node.

#include<bits/stdc++.h>
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
//recursive function
void mirror(Node* root){
    Node* temp;
    if(root==NULL){
        return;
    }
    else{
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }

}
//Iterative Function
//
// void mirror(Node* root){
//     if(root == NULL)
//         return;
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         Node* cur=q.front();
//         q.pop();
//         Node* temp;
//         temp=cur->left;
//         cur->left=cur->right;
//         cur->right=temp;
//         if(cur->left)
//             q.push(cur->left);
//         if(cur->right)
//             q.push(cur->right);    
//     }
// }



int main(){
    Node* root=newNode(1);
    root->left=newNode(3);
    root->right=newNode(2);
    root->right->left=newNode(5);
    root->right->right=newNode(4);
    cout<<"Normal : ";
    inorder(root); 
    cout<<endl;
    mirror(root);
    cout<<"Mirror : ";
    inorder(root); 
    cout<<endl;
    return 0;
}
