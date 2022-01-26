#include<bits/stdc++.h>
using namespace std;

// flattening a binary tree includes converting the given binary tree into
// linked list with the preorder sequence.
// left node contains the null and the right node acts as next node
// we cannot use any other data structure

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node* root){
    
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->left != NULL){
        flatten(root->left);
    }
    if(root->right != NULL){
        flatten(root->right);
    }

    Node* t = root->left;
    while(t->right != NULL){
        t=t->right;
    }
    Node* temp = root->right;
    root->right = root->left;
    root->left = NULL;
    t->right = temp;

    return;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    inorder(root);
    cout<<endl;
    flatten(root);
    inorder(root);
    return 0;
}