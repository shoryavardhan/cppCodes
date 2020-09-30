#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int n){
    Node* node = new Node;
    node->data = n;
    node->right = node ->left = NULL;
    return node;
} 

int sumOfLevelProduct(Node* root){
    queue<Node *>q;
    cout<<root->data<<" ";
    q.push(root);
    q.push(NULL);
    int sum = 0;
    int product = 1;
    while(q.empty()== false){
        Node *temp = q.front();
        if(temp !=  NULL){
            product*=temp->data;
            cout<<temp->data<<" "<<product<<"\n ";
            if(temp->left  != NULL){
                q.push(temp->left);
                
            }
            if(temp->right  != NULL){
                q.push(temp->right);
            }
        }
        else{
            if(q.empty()){
                q.push(NULL);
            }
            cout<<"\n";
            sum+=product;
            product=1;
        }
    }
    return sum;
}
int main (){
    Node *root = newNode(9); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->left->left->left = newNode(8); 
    int sum = sumOfLevelProduct(root);
    // cout<<sum;
    return 0;
}