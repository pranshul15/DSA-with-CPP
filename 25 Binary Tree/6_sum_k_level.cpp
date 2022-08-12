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

int sum_K(Node* root,int k){
    if(root == NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    if(k==0){
        return root->data;
    }

    int var = 0,ans = 0;
    
    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        

        if(node != NULL){
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
            if(var == k){
                ans+=node->data;
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            var++;
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    cout<<sum_K(root,2)<<endl;

    return 0;
}