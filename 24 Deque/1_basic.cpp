#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> de;
    de.push_front(1);
    de.push_back(0);
    de.push_front(3);
    de.push_back(2);
    cout<<de.back()<<endl;
    cout<<de.front()<<endl;
    de.pop_back();
    cout<<de.back()<<endl;
    de.pop_front();
    cout<<de.front()<<endl;
    return 0;
}