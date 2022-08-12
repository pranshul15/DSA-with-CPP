#include<iostream>
#include<limits.h>

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


// video's approach
void countPointers(Node* root,Node**first,Node**mid,
                            Node**last,Node**prev){
    
    if(root==NULL){
        return;
    }

    countPointers(root->left,first,mid,last,prev);
    if(*prev && root->data < (*prev)->data){
        if(!(*first)){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev = root;
    countPointers(root->right,first,mid,last,prev);
}

void recoverBST(Node* root){
    Node* first,*mid,*last,*prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    countPointers(root,&first,&mid,&last,&prev);

    if(first && last){
        swap(first->data,last->data);
    }
    else if(first && mid){
        swap(first->data,mid->data);
    }
}

// inorder
void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(4);
    root->left->right = new Node(6);
    root->left->right->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(5);
    root->right = new Node(12);
    root->right->right = new Node(15);
    root->right->left = new Node(9);
    root->right->left->right = new Node(10);
    inorderPrint(root);
    cout<<endl;
    recoverBST(root);
    inorderPrint(root);
    return 0;
}