#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int n)
{
    Node *node = new (Node);
    node->data = n;
    node->left = node->right = NULL;
    return node;
}
Node *createBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = newNode(arr[mid]);
    root->left = createBST(arr, start, mid - 1);
    root->right = createBST(arr, mid + 1, end);

    return root;
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void kthLargest(Node *root, int k, int &c)
{
    if(root == NULL || c>k){
        return;
    }
    kthLargest(root->right, k, c);
    // cout << root->data << " ";
    c++;
    if(c==k){
        cout<<root->data;
        return;
    }
    kthLargest(root->left, k, c);


   
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// void kthLargest(Node* root){

// }
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createBST(arr, 0, n - 1);
    int k = 4 ;
    int c = 0;
    // cout<<"preorder traversal- ";
    // preorder(root);
    // cout<<endl;
    cout <<k<< "th Largest = ";
    kthLargest(root, k, c);
   
    cout << endl;
    // cout<<"postorder traversal- ";
    // postorder(root);
    // cout<<endl;
    // kthLargest(root);
    return 0;
}