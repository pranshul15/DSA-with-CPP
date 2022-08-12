// diameter in binary tree is the longest distance between two leaves
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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left),height(root->right)) + 1;
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh + rh + 1 , max( diameter(root->left) , diameter(root->right) ));
}

int diametero(Node* root, int* height){
    if(root==NULL){
        *height = 0;
        return 0;
    }

    int lh=0,rh=0;
    int ld = diametero(root->left , &lh);
    int rd = diametero(root->right , &rh);

    int currdiameter = lh + rh + 1;
    *height = max(lh,rh) + 1;

    return max(currdiameter,max(ld,rd));
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);
    
    // cout<<diameter(root)<<endl;
    int height = 0;
    cout<<diametero(root,&height)<<endl;
    cout<<height<<endl;
    return 0;
}