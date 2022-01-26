#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root== NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    struct Node* root = new Node(14);
    root->left = new Node(10);
    root->left->right = new Node(12);
    root->left->right->left = new Node(11);
    root->left->left = new Node(8);
    root-> right = new Node(17);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(20);
    root->right->right->left = new Node(18);
    root->right->right->right = new Node(25);
    root->right->right->right->left = new Node(22);
    root->right->right->right->left->right = new Node(23);
    
    // preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    // postorder(root);
    cout<<endl;
    return 0;
}