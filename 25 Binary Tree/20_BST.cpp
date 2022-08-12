#include<iostream>
using namespace std;

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

Node* insertAtBST(Node* root,int key){
    if(root == NULL){
        return new Node(key);
    }

    if(root->data > key){
        root->left = insertAtBST(root->left,key);
    }
    else{
        root->right = insertAtBST(root->right,key);
    }
    return root;
}

Node* searchBST(Node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data > key){
        return searchBST(root->left,key);
    }
    return searchBST(root->right,key);
}

Node* deleteBST(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data < key){
        root->right = deleteBST(root->right,key);
    }
    else if(root->data > key){
        root->left = deleteBST(root->left,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            root = temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            root = temp;
        }
        else{
            swap(root->data,root->right->data);
            root->right = deleteBST(root->right,key);
        }
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
    Node* root = NULL;
    root = insertAtBST(root,5);
    root = insertAtBST(root,3);
    root = insertAtBST(root,2);
    root = insertAtBST(root,4);
    root = insertAtBST(root,8);
    root = insertAtBST(root,6);
    inorderPrint(root);
    cout<<endl;
    if(searchBST(root,10) == NULL){
        cout<<"node doesn't exist"<<endl;
    }
    else{
        cout<<"node exists"<<endl;
    }
    root = deleteBST(root,8);
    inorderPrint(root);
    return 0;
}