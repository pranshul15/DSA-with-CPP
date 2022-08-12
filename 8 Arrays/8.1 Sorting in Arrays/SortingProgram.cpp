//to arrange the given array in ascending order for integers
#include <iostream>
using namespace std;

void SoringArray(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int var=arr[j];
                arr[j]=arr[i];
                arr[i]=var;
            }
        }
    }
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
    return;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SoringArray(arr,n);

    return 0;
}