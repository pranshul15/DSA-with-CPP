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

// lca stands for least common node
// least common node means 

Node* lca (Node* root, int n1, int n2){

    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 or root->data == n2) {
        return root;
    }

    Node* left = lca(root->left,n1,n2);
    Node* right = lca(root->right,n1,n2);

    if(left == NULL and right == NULL) {
        return NULL;
    }

    if(left != NULL and right != NULL) {
        return root;
    }

    if(left != NULL and right == NULL){
        return lca(root->left,n1,n2);
    }
    return lca(root->right,n1,n2);
}

int dist(Node* root , int k , int distance) {
    if(root == NULL){
        return -1;
    }
    if(root->data == k) {
        return distance;
    }

    int left = dist(root->left,k,distance+1);
    if(left != -1){
        return left;
    }

    return dist(root->right,k,distance+1);

}

int smallest_dist (Node* root, int n1, int n2){
    Node* lCA = lca(root,n1,n2);
    int r1 = dist(lCA,n1,0);
    int r2 = dist(lCA,n2,0);
    return r1+r2;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<smallest_dist(root,5,6);
    return 0;
}