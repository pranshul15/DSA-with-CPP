#include<bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL and root2==NULL){
        return true;
    }
    else if(root1==NULL or root2==NULL){
        return false;
    }
    else{
        bool a = root1->data == root2->data;
        bool left = isIdentical(root1->left,root2->left);
        bool right = isIdentical(root1->right,root2->right);
        return a && (left && right);
    }
}

int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right = new Node(8);
    root1->right->left = new Node(6);
    root1->right->right = new Node(9);
    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->left->left = new Node(1);
    root2->left->right = new Node(4);
    root2->right = new Node(8);
    root2->right->left = new Node(6);
    root2->right->right = new Node(9);

    if(isIdentical(root1,root2)){
        cout<<"identical BST's"<<endl;
    }
    else{
        cout<<"non identical BST's"<<endl;
    }
    return 0;
}