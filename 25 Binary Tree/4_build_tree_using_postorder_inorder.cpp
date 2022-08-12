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
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}

Node* build_tree(int postorder[],int inorder[],int start,int end){
    static int idx = end;
    
    if(start>end){
        return NULL;
    }
    
    int val = postorder[idx];
    idx--;
    int curr = search(inorder,start,end,val);

    Node* root = new Node(val);
    
    if(start == end){
        return root;
    }

    root->right = build_tree(postorder,inorder,curr+1,end);
    root->left = build_tree(postorder,inorder,start,curr-1);

    return root;
}

void inorderp(Node* root){
    if(root==NULL){
        return;
    }
    inorderp(root->left);
    cout<<root->data<<" ";
    inorderp(root->right);
}

int main(){
    int postorder[] = {4,5,2,6,7,3,1};
    int inorder[] = {4,2,5,1,6,3,7};

    Node* root = build_tree(postorder,inorder,0,6);
    inorderp(root);
    return 0;
}