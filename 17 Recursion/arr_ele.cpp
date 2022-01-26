//to find the first and the last index of an element in an array
#include<bits/stdc++.h>
using namespace std;

int firstocc(int arr[],int n,int key,int i){
    if(arr[i]==key){
        return i;
    }
    if(i==n){
        return -1;
    }
    return firstocc(arr,n,key,i+1);
}

int lastocc(int arr[],int n,int key,int i){
    if(arr[i]==key){
        return i;
    }
    if(i==0){
        return -1;
    }
    return lastocc(arr,n,key,i-1);
}

int lasocc(int arr[],int n,int key,int i){
    int rest = lasocc(arr,n,key,i+1);
    if(rest != -1){
        return rest;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}

int main(){
    int arr[]={7,2,5,2,8,2,4};
    cout<<firstocc(arr,7,2,0);
    cout<<lastocc(arr,7,2,6);
    return 0;
}