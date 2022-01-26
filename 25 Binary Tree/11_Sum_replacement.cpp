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

void sumReplacement(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left !=NULL and root->right != NULL){
        sumReplacement(root->left);
        sumReplacement(root->right);
        root->data = root->data + root->left->data + root->right->data;
    }
    else if(root->left != NULL and root->right == NULL){
        sumReplacement(root->left);
        root->data = root->data + root->data;
    }
    else if(root->left == NULL and root->right != NULL){
        sumReplacement(root->right);
        root->data = root->data + root->right->data;
    }
    
    return;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    sumReplacement(root);
    preorder(root);
    return 0;
}