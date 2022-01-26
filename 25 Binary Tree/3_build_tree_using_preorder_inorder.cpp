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

int search(int inorder[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i] == val){
            return i;
        }
    }
    return -1;
}

Node* build_tree(int preorder[],int inorder[],int start, int end){
    static int idx = 0;
    
    if(start > end){
        return NULL;
    }
    
    int val = preorder[idx];
    idx++;
    int curr = search(inorder,start,end,val);
    
    Node* root = new Node(val);
    
    if(start == end){
        return root;
    }
    
    root->left = build_tree(preorder,inorder,start,curr-1);
    root->right = build_tree(preorder,inorder,curr+1,end);
    
    return root;
}

void inorderp(Node* root){
    if(root == NULL){
        return;
    }
    
    inorderp(root->left);
    cout<<root->data<<" ";
    inorderp(root->right);
}

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    Node* root = build_tree(preorder,inorder,0,4);
    
    inorderp(root);
    return 0;
}