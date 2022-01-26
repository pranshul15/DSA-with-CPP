#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> u;
    u.insert(5);
    u.insert(2);
    u.insert(8);
    u.insert(3);
    u.insert(8);
    for(auto i=u.begin();i!=u.end();i++){
        cout<<*i<<" ";
    }
    return 0;
}