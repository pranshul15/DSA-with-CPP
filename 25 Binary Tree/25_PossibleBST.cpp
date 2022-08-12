#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// total number of possible BST is equal to the
// catalan number
vector<Node*> constructPossibleBST(int start,int end){
    vector<Node*> ans;
    if(start > end){
        ans.push_back(NULL);
        return ans;
    }
    
    for(int i=start;i<=end;i++){
        vector<Node*> leftSubtree = constructPossibleBST(start,i-1);
        vector<Node*> rightSubtree = constructPossibleBST(i+1,end);

        for(int j=0;j<leftSubtree.size();j++){
            Node* left = leftSubtree[j];
            for(int k=0;k<rightSubtree.size();k++){
                Node* right = rightSubtree[k];
                Node* root = new Node(i);
                root->left = left;
                root->right = right;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

void printPreorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    vector<Node*> trees = constructPossibleBST(1,3);
    for(int i=0;i<trees.size();i++){
        cout<<i+1<<" : ";
        printPreorder(trees[i]);
        cout<<endl;
    }
    return 0;
}