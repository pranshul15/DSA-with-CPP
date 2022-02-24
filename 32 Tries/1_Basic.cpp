#include<bits/stdc++.h>
using namespace std;

class Trie
{
public:
    class node
    {
    public:
        bool end;
        node* next[26];
        
        // constructor of node
        node() {
            end = false;
            for(int i=0;i<26;i++)
                next[i] = NULL;
        }
    };

    node* trie;

    Trie();
    void insert(string word);
    bool search(string word);
};

// constructor of trie
Trie::Trie()
{
    trie = new node();
}

// insert function in trie
void Trie:: insert(string word){
    node* it = trie;
    for(int i=0;i<word.size();i++){
        if(it->next[word[i] - 'a'] == NULL)
            it->next[word[i]-'a'] = new node();
        it = it->next[word[i]-'a'];
    }
    it->end = true;
}

// search function in trie
bool Trie:: search(string word){
    node* it = trie;
    for(int i=0;i<word.size();i++){
        if(it->next[word[i]-'a'] == NULL){
            return false;
        }
        it = it->next[word[i]-'a'];
    }
    return it->end;
}

int main(){
    Trie mytrie;
    vector<string> v(2);

    for(int i=0;i<2;i++)
        cin>>v[i];

    for(int i=0;i<v.size();i++)
        mytrie.insert(v[i]);
    
    vector<string> search(3);

    for(int i=0;i<3;i++)
        cin>>search[i];

    for(int i=0;i<search.size();i++){
        if(mytrie.search(search[i]) == true){
            cout<<"true\n";
        }
        else{
            cout<<"false\n";
        }
    }

    return 0;
}