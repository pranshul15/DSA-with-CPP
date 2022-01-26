#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

void zigzagTraversal(Node* root){
    stack<Node*> curr;
    stack<Node*> next;
    bool leftToRight = true;
    curr.push(root);
    
    while(curr.size()!=0){
        while(curr.size()!=0){
            Node* temp = curr.top();
            curr.pop();
            
            if(leftToRight){
                if(temp->left!=NULL){
                    next.push(temp->left);
                }
                if(temp->right!=NULL){
                    next.push(temp->right);
                }
                cout<<temp->data<<" ";
            }

            else{
                if(temp->right!=NULL){
                    next.push(temp->right);
                }
                if(temp->left!=NULL){
                    next.push(temp->left);
                }
                cout<<temp->data<<" ";
            }
        }
        swap(curr,next);
        leftToRight = !leftToRight;
    }
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right = new Node(8);
    root->right->right = new Node(11);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(12);
    zigzagTraversal(root);
    return 0;
}