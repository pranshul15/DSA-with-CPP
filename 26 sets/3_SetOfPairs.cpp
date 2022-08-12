#include<iostream>
#include<set>
using namespace std;

int main(){
    set<pair<int,int>> s;
    s.insert({5,6});
    s.insert({5,7});
    s.insert({6,7});
    s.insert({4,10});
    s.insert({5,6});
    set<pair<int,int>> :: iterator it = s.begin();
    while(it!=s.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}