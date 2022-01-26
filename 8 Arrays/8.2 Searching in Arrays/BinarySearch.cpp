//to Search from given sorted array
#include<iostream>
using namespace std;

int BinarySearch(int array[],int n,int key){
    int s=0;int e=n;
    int mid=(s+e)/2;
    while(s<=n){
        if(array[mid]==key){return mid;}
        else if(array[mid]>key){e=mid-1;}
        else{s=mid+1;}
    }
    return -1;
}

int main(){
    int n;cout<<"Array size";cin>>n;
    int arr[n];cout<<"elements of array ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<endl;
    int key;cout<<"enter 'key'";cin>>key;
    cout<<"Binary Search Result "<<BinarySearch(arr,n,key);
    return 0;
}