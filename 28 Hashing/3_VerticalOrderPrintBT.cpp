#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef vector<int> vi;

struct Node
{
    int data;
    Node *left,*right;
};

Node* newNode(int key){
    Node* n = new Node;
    n->data = key;
    n->left = n->right = NULL;
    return n;
}

void HorizontalDistance(Node* root, int HD, map<int,vi> &m){
    if(root == NULL){
        return;
    }
    
    m[HD].push_back(root->data);

    HorizontalDistance(root->left,HD-1,m);
    HorizontalDistance(root->right,HD+1,m);
    
}

int main(){
    Node* root = newNode(10);
    root->left = newNode(7);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->right = newNode(14);
    root->right->left = newNode(12);
    root->right->right = newNode(16);

    map<int,vi> m;

    HorizontalDistance(root,0,m);

    map<int,vi> :: iterator it;
    for(it = m.begin();it != m.end(); it++){
        for(int j=0;j<(it->second).size();j++){
            cout<<(it->second)[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}