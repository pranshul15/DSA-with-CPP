#include<bits/stdc++.h>
using namespace std;

int knapsack(int w[],int v[],int W,int n){
    if(n==0 || W==0){
        return 0;
    }

    if(W<w[n-1]){
        return knapsack(w,v,W,n-1);
    }
    return max(knapsack(w,v,W-w[n-1],n-1)+v[n-1],knapsack(w,v,W,n-1));
}

int main(){
    int n;
    cout<<"enter the value of n ";
    cin>>n;
    int w[n];
    cout<<"enter the weight elements "<<endl;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    int v[n];
    cout<<"enter the values of corresponding elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int W;
    cout<<"Enter the value of maximum weight "<<endl;
    cin>>W;
    
    cout<<endl<<knapsack(w,v,W,n);

    return 0;
}