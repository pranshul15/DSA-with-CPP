#include<bits/stdc++.h>
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

bool getPath(Node* root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}

bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }

    return search(root->left,key) || search(root->right,key);
}

void path(Node* root,int key,vector<int> &vect){
    if(root==NULL){
        return;
    }
    
    vect.push_back(root->data);
    
    if(root->data == key){
        return;
    }

    if(search(root->left,key)){
        path(root->left,key,vect);
    }
    if(search(root->right,key)){
        path(root->right,key,vect);
    }
}

int LCA(Node* root,int n1,int n2){
    vector<int> path1,path2;

    if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
        return -1;
    }

    int pc =0;
    while(1){
        if(path1[pc]!=path2[pc]){
            break;
        }
        pc++;
    }
    return path1[pc-1];
}

int LCA2(Node* root,int n1,int n2){
    vector<int> path1,path2;
    path(root,n1,path1);
    path(root,n2,path2);

    int pc = 0;
    while(1){
        if(path1[pc] != path2[pc]){
            break;
        }
        pc++;
    }
    return path1[pc-1];
}

Node* LCA3(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    
    Node* left = LCA3(root->left,n1,n2);
    Node* right = LCA3(root->right,n1,n2);

    if(left == NULL && right == NULL){
        return NULL;
    }

    if(left != NULL && right != NULL){
        return root;
    }
    else if(left != NULL && right == NULL){
        return LCA3(root->left,n1,n2);
    }
    return LCA3(root->right,n1,n2);
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
    cout<<LCA2(root,10,14)<<"\n";
    return 0;
}