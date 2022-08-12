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

int maxSumUtil(Node* root, int &ans){
    if(root==NULL){
        return 0;
    }

    int l = maxSumUtil(root->left,ans);
    int r = maxSumUtil(root->right,ans);

    int nodeMax = max(max(root->data,root->data+l+r),
                max(root->data+l,root->data+r));
    ans = max(ans,nodeMax);
    int singlePathSum = max(root->data,
                max(root->data+l,root->data+r));
    return singlePathSum;
}

int maxSum(Node* root){
    int ans = INT_MIN;
    maxSumUtil(root,ans);
    return ans;
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
    cout<<maxSum(root)<<endl;
    return 0;
}