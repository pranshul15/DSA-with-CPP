#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number of days ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the value of stocks ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int profit=0,i=0,j=1;
    
    while(j<n){
        if(arr[j]>arr[i]){
            profit = profit + (arr[j]-arr[i]);
            j++;
        }
        else{
            i=j;
            j++;
        }
    }

    cout<<profit;

    return 0;
}