// to create a balanced bst from sorted array
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

Node* constructBST(int a[],int st,int en){
    int mid = (st + en)/2;
    Node* root = new Node(a[mid]);
    if(st!=mid){
        root->left = constructBST(a,st,mid-1);
    }
    if(en!=mid){
        root->right = constructBST(a,mid+1,en);
    }
    return root;
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int arr[] = {10,20,30,40,50};
    Node* root = constructBST(arr,0,4);
    inorderPrint(root);    
    return 0;
}