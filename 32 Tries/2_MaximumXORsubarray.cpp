#include<bits/stdc++.h>
using namespace std;

int p2[31];

int getBit(int n,int pos){
    return (n & (1<<pos))!=0;
}

class Trie
{
public:
    class node
    {
    public:
        node* children[2];
        node() {
            children[0] = children[1] = NULL;
        }
    };

    node* trie;

    Trie() {
        trie = new node();
    }
    void insert(int num);
    pair<int,int> maxXOR();
};

void Trie::insert(int n){
    node* it = trie;
    for(int i=30 ; i>=0 ; i--){
        int x = getBit(n,i);

        if(it->children[x] == NULL)
            it->children[x] = new node();

        it = it->children[x];
    }
}

pair<int,int> Trie::maxXOR(){
    node* it1 = trie;
    node* it2 = trie;
    int a=0,b=0;

    // for a
    for(int i=30 ; i>=0 ; i--){
        if(it1->children[0] == NULL && it1->children[1] == NULL)
            break;
        if(it1->children[0] != NULL)
            it1 = it1->children[0];
        else if(it1->children[0] == NULL && it1->children[1] != NULL){
            a += p2[i];
            it1 = it1->children[1];
        }
    }

    // for b
    for(int i=30 ; i>=0 ; i--){
        if(it2->children[0] == NULL && it2->children[1] == NULL)
            break;
        if(it2->children[1] != NULL){
            b += p2[i];
            it2 = it2->children[1];
        }
        else if(it2->children[1] == NULL && it2->children[0] != NULL)
            it2 = it2->children[0];
    }

    return {a,b};
}

int main(){
    p2[0]=1;
    for(int i=1;i<32;i++)
        p2[i] = p2[i-1]*2;

    int n;cin>>n;
    vector<int> v(n);

    Trie mytrie;

    for(int i=0;i<n;i++){
        cin>>v[i];
        mytrie.insert(v[i]);
    }

    pair<int,int> ans = mytrie.maxXOR();
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}