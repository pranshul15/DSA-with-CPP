//bubble sort of array
#include<iostream>
using namespace std;


void BubbleSort(int arr[],int n){
    for(int i=0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n-i ; j++){
            if(arr[i]>arr[j]){
                int var=arr[j];
                arr[j]=arr[i];
                arr[i]=var;
            }
        }
    }
    for(int i=0 ; i<n ; i++){cout<<arr[i]<<" ";}
    return;
}

int main(){
    int n;cout<<"Array size ";cin>>n;
    int arr[n];
    cout<<"Array elements";
    for(int i=0;i<n;i++){cin>>arr[i];}
    BubbleSort(arr,n);
    return 0;
}