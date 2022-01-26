#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=10;
    int*aptr;
    aptr=&a;

    cout<<*aptr<<endl;
    *aptr=20;
    cout<<*aptr<<endl;

    return 0;
}