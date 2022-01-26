#include <bits/stdc++.h>
using namespace std;

//node at k can be two nodes
//one can be in the subtree of the node
//one can be in the ancestor of the node

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

// My code

Node* search(Node* root,int n){
    if(root == NULL || root->data == n){
        return root;
    }
    Node* left = search(root->left,n);
    if(left != NULL){
        return left;
    }
    return search(root->right,n);
}

int dist(Node* root,Node* target,int distance){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        return distance;
    }
    int ld = dist(root->left,target,distance+1);
    if(ld != -1){
        return ld;
    }
    return dist(root->right,target,distance+1);
}

void subtree_nodes_k(Node *root,int k){
// this functions is used to print the nodes k below the node root
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    for(int i=0;i<=k;i++){
        while(q.front() != NULL){
            Node* temp = q.front();
            q.pop();
            if(i==k){
                cout<<temp->data<<" ";
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        if(q.front()==NULL){
            q.pop();
        }
        if(q.size()==0){
            break;
        }
        else{
            q.push(NULL);
        }
    }
}

void print(Node* root,Node* t,int k){
    
    if(root == t){
        subtree_nodes_k(root,k);
        return;
    }

    int d = dist( root,t,0 );

    if(search(root->left,t->data) != NULL ){
    // if target is present in left side
        if( d<k ){
            subtree_nodes_k(root->right,k-d-1);
        }
        else if (d==k){
            cout<<root->data<<" ";
        }
        
        print(root->left,t,k);
    }
    else{
    // if target is present in right side
        if(d<k){
            subtree_nodes_k(root->left,k-d-1);
        }
        else if (d==k){
            cout<<root->data<<" ";
        }
        print(root->right,t,k);
    }
    return;
}

// /My code

// case 1
void printSubtreeNodes(Node* root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    }

    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

// case 2
int printNodesAtk(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printSubtreeNodes(root,k);
    }

    int dl = printNodesAtk(root->left,target,k);
    if(dl != -1){
        if(dl+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr = printNodesAtk(root->right,target,k);
    if(dr != -1){
        if(dr+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }

    return -1;
}

int main()
{
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
    int n;
    cin>>n;
    Node* t = search(root,n);
    print(root,t,3);
    return 0;
}