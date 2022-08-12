/*
Neha has a digital dictionary. It has an input field in which one can search any string 
and the dictionary displays all the words whose prefix is that input string in lexicographical 
order.

Now you are given a task to make your own digital dictionary. You will be given words that you 
can store in your database and then you need to design the search functionality. And if no such 
words are available for a given search word, add this word to your dictionary.
*/
#include<bits/stdc++.h>
using namespace std;

class node
{
private:
    node* next[26];
    bool end;
public:
    node() {
        for(int i=0 ; i<26 ; i++){
            next[i] = NULL;
        }
        end = false;
    }
};

class Trie
{
private:
    node* trie;
public:
    Trie() {
        trie = new node();
    }
};

int main(){
    return 0;
}