#include<iostream>
#include<queue>
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

void left_view(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int l = q.size();
        for(int i=0;i<l;i++){
            Node* n = q.front();
            q.pop();
            if(n->left != NULL){
                q.push(n->left);
            }
            if(n->right != NULL){
                q.push(n->right);
            }
            if(i==0){
                cout<<n->data<<" ";
            }
        }
    }
    return;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);
    root->left->left->left = new Node(8);
    left_view(root);
    return 0;
}