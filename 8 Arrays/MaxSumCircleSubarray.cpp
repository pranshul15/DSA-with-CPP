#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
    int currsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        if(currsum<0){
            currsum=0;
        }
        maxsum=max(maxsum,currsum);
    }
    return maxsum;
}
//non wrapped implies not contributing
//wrapped implies implies contributing
//wrapsum = total sum - non wrapped sum
int maxsumcircle(int a[],int n){
    int wrapsum;
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=a[i];
        a[i]=-a[i];
    }
    int nonwrapsum=-kadane(a,n);
    wrapsum=totalsum-nonwrapsum;
    return wrapsum;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    cout<<maxsumcircle(a,n);
    return 0;
}