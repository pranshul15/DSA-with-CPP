#include<iostream>
using namespace std;

void count_sort(int arr[],int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[k+1]={0};
    //making the count array
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    //modify count array according to index
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    //new array for insertion of elements
    int output[n];
    for(int i=n-1;i>=0;i--){
        //reducing by one gives the index of the number
        count[arr[i]]--;
        //putting the number in the given index from the actual array to output array
        output[count[arr[i]]]=arr[i];
    }
    //putting the values of output array to actual array
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    count_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}