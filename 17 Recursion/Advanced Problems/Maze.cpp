#include<bits/stdc++.h>
using namespace std;

int maze(int n,int i,int j){
    if(i>=n || j>=n){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 0;
    }
    if(i==n-1 || j==n-1){
        return 1;
    }
    return maze(n,i+1,j) + maze(n,i,j+1);
}

int main(){
    int n;
    cout<<"Enter the size of side of square ";
    cin>>n;
    cout<<endl<<maze(n,0,0);
    return 0;
}