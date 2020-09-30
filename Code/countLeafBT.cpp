#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int n)
{
    Node *node = new Node;
    node->data = n;
    node->left = node->right = NULL;
}

int countLeaf(Node *root)
{   
    if(root->left==NULL && root->right ==NULL){
        return 1;
    }
    return countLeaf(root->left)+countLeaf(root->right);    
}

int main()
{
    Node* root = newNode(1);
    root->left=newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(4);
    root->left->right->left = newNode(5);
    root->left->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right ->right= newNode(7);
    cout<<countLeaf(root);
    return 0;
}
 