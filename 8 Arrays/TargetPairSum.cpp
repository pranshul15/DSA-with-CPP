#include<bits/stdc++.h>
using namespace std;

bool targetpairsum(int arr[],int n,int k){
    int low=0,high=n-1;
    while(low<high){
        if(arr[low]+arr[high]==k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low]+arr[high]>0){
            high--;
        }
        else{
            low++;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    int k;cin>>k;
    cout<<targetpairsum(a,n,k);
    return 0;
}