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

Node* constructBST(int preorder[],int* preorderidx,int key,int min,int max,int n){
    if(*preorderidx >= n){
        return NULL;
    }

    Node* root = NULL;
    if(key<max and key>min){
        root = new Node(key);
        *preorderidx = *preorderidx + 1;

        if(*preorderidx < n){
            root->left = constructBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx < n){
            root->right = constructBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }

    return root;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    int a[]={7,5,4,6,8,9};
    int n = 6;
    int preorderidx = 0;
    Node* root = constructBST(a,&preorderidx,a[0],INT_MIN,INT_MAX,n);
    printInorder(root);
    return 0;
}