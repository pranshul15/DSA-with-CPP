#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    map<int,int> m;
    m[5] = 16;
    m[2] = 4;

    unordered_map<int,int> ump;
    ump[4] = 2;
    ump[1] = 5;
    ump[6] = 80;
    return 0;
}