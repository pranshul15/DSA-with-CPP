#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node* left;
    node* right;
    node(int val, node* left, node* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

node* build_tree(vector<int> &preorder, map<int,int> &inorder_map, int st, int en) {
    static int idx = 0;
    if(st>en) {
        return NULL;
    }
    int val = preorder[idx++];
    int j = inorder_map[val];
    return new node(val,
                    build_tree(preorder,inorder_map,st,j-1),
                    build_tree(preorder,inorder_map,j+1,en));
}

int main() {
    int N;
    cin>>N;
    vector<int> preorder(N);
    vector<int> inorder(N);
    for(int i=0 ; i<N ; i++){
        cin>>preorder[i];
    }
    for(int i=0 ; i<N ; i++){
        cin>>inorder[i];
    }   
    map<int,int> inorder_map;
    for(int i=0 ; i<N ; i++) {
        inorder_map.insert(inorder[i],i);
    }
    node* root = build_tree(preorder,inorder_map,0,N-1);
    return 0;
}