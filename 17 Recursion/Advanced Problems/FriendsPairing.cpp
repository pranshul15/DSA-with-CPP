#include<bits/stdc++.h>
using namespace std;

int friends_pair(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return friends_pair(n-1) + (n-1)*friends_pair(n-2);
}

int main(){
    int n;
    cout<<"Enter the number of friends ";
    cin>>n;
    cout<<friends_pair(n);
    return 0;
}