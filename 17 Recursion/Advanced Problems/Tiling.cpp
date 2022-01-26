#include<bits/stdc++.h>
using namespace std;

int tiling(int n){
    if(n==1 || n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return tiling(n-1) +tiling(n-2);
}

int main(){
    int n;
    cout<<"Enter the number of columns ";
    cin>>n;
    cout<<endl<<tiling(n);
    return 0;
}