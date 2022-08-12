//Sorting an array using method of insertion sort
#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j+1]<arr[j]){
                int k=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=k;
            }
        }
    }
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
    return;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}
    InsertionSort(arr,n);
    return 0;
}