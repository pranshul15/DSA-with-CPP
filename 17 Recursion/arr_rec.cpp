//To check whether an array is sorted or not
#include<bits/stdc++.h>
using namespace std;

bool sortarr(int arr[],int n){
    
    if(n==1){
        return true;
    }
    bool restarr = sortarr(arr+1,n-1);
    return (arr[0]<arr[1] && restarr);
}

int main(){
    int arr[]={1,2,3,4,5};
    cout<<sortarr(arr,5);
    return 0;
}