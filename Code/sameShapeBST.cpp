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
int isSameStructure(Node* a, Node* b) 
{ 
	if (a==NULL && b==NULL) 
		return 1; 

	if (a!=NULL && b!=NULL) 
	{ 
		return
		( 
			isSameStructure(a->left, b->left) && 
			isSameStructure(a->right, b->right) 
		); 
	} 
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

    Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    root2->right->left = newNode(6);
    root2->right->right = newNode(7);
    root2->left->left->left = newNode(4);
    root2->left->left->right = newNode(4);
    root2->left->right->left = newNode(5);
    root2->left->right->right = newNode(5);
    root2->right->left->left = newNode(6);
    root2->right->left->right = newNode(6);
    root2->right->right->left = newNode(7);
    //root2->right->right ->right= newNode(7);

	if (isSameStructure(root, root2)) 
		cout<<"Both trees have same structure"; 
	else
		cout<<"Trees do not have same structure"; 

	return 0; 
} 
