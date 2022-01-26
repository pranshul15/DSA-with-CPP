#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i = s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i = s.rbegin();i!=s.rend();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<s.size();
    cout<<endl;
    
    // Custom Comparater
    
    set<int,greater<int>> q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(3);
    for(auto i:q){
        cout<<i<<" ";
    }
    
    // multiset

    multiset<int> m;
    m.insert(1);
    m.insert(2);
    m.insert(3);
    m.insert(3);
    m.insert(3);
    m.insert(3);
    for(auto i:m){
        cout<<i<<" ";
    }
    cout<<endl;
    m.erase(3);
    for(auto i:m){
        cout<<i<<" ";
    }
    cout<<endl;
    multiset<int> k;
    k.insert(1);
    k.insert(2);
    k.insert(3);
    k.insert(3);
    k.insert(3);
    k.insert(3);
    for(auto i:k){
        cout<<i<<" ";
    }
    cout<<endl;
    k.erase(k.find(3));
    for(auto i:k){
        cout<<i<<" ";
    }
    
    return 0;
}