#include <iostream> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 
int maxDepthNode(Node* a) 
{ 
    
    return 0;
} 

int main() 
{ 
	Node* root = newNode(1);
    root->left = newNode(2);
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

 

	return 0; 
} 
