//max till ith element in an array
#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){cin>>arr[i];}
    int mx=arr[0];
    for (int i=0;i<n;i++){
        mx=max(arr[i],mx);
        cout<<mx;
    }

    return 0;
}