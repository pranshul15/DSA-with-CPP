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

// balanced binary tree means that height should be same for
// each node for both left and right

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh,rh) + 1;
}

bool balanced_tree(Node* root){
    if(root==NULL){
        return true;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh != rh){
        return false;
    }
    bool lb = balanced_tree(root->left);
    bool rb = balanced_tree(root->right);
    return true;
}

bool balanced(Node* root, int* height){
    if(root==NULL){
        *height = 0;
        return true;
    }

    int lh=0,rh=0;

    bool lb = balanced(root->left,&lh);
    bool rb = balanced(root->right,&rh);
    
    if(lh != rh){
        return false;
    }

    *height = max(lh,rh) + 1;
    return true;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    // root->right->right->left = new Node(6);
    int height = 0;
    if(balanced(root,&height)){
        cout<<"balanced tree"<<endl;
    }
    else{
        cout<<"unbalanced tree"<<endl;
    }
    return 0;
}