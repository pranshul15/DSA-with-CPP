#include<iostream>
#include<bits/stdc++.h>
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

bool checkBST(Node* root,int min,int max){
    if(root == NULL){
        return true;
    }

    bool l = checkBST(root->left,min,root->data);
    bool r = checkBST(root->right,root->data,max);
    bool flag;
    
    if(root->data>min and root->data<max){
        flag = true;
    }
    else{
        flag = false;
    }

    return flag && (l && r);
}

void BST(Node* root){
    if(checkBST(root,INT_MIN,INT_MAX)){
        cout<<"It is a BST"<<endl;
    }
    else{
        cout<<"It is not a BST"<<endl;
    }
}

int main(){
    Node* root = new Node(7);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right = new Node(8);
    root->right->right = new Node(9);
    BST(root);
    return 0;
}