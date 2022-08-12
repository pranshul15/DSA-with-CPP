#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=10;
    int*apointer;
    apointer=&a;
    cout<<*apointer<<endl;
    int**bpointer;
    bpointer=&apointer;
    cout<<**bpointer<<endl;
    return 0;
}