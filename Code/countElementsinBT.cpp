#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *left,*right;
};
Node* newNode(int n){
    Node* node =new Node;
    node->info = n;
    node->left=node->right=NULL;
    return (node);
}
int totalElements(Node* root){
    if(root==NULL){
        return 0;
    }
    return totalElements(root->left)+totalElements(root->right)+1;
}
int main()
{
    struct Node *root = newNode(2); 
    root->left     = newNode(7); 
    root->right     = newNode(5); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(1); 
    root->left->right->right = newNode(11); 
    root->right->right = newNode(9); 
    root->right->right->left = newNode(4);
    root->right->right->left->right = newNode(4);
    cout<<totalElements( root);
    return 0;
}
