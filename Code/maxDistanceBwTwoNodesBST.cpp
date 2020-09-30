#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *left, *right;
};
Node *newNode(int n)
{
    Node *node = new Node;
    node->info = n;
    node->left = node->right = NULL;
    return (node);
}
int max(int a, int b){
    return (a>=b)?a:b;
}
int height(Node *root)
{
    if(root == NULL){
        return 0;
    }
    return (1+max(height(root->left),height(root->right)));
}
int maxdistance(Node *root)
{
       if(root == NULL){
        return 0;
    }
    int lh= height(root->left);
    int rh =  height(root->right);

    int ld = maxdistance(root->left);
    int rd = maxdistance(root->right);

    return max(lh+rh+1,max(ld,rd));
}
int main()
{
    struct Node *root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);
    root->right->right->left->right = newNode(4);
    cout << maxdistance(root);
    return 0;
}