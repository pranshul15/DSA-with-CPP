#include<bits/stdc++.h>
using namespace std;

//to check whether sum is equal to k
bool check (int arr[],int k,int i){    
    int low=0,high=i-1;

    while(low<high){
        if(arr[low]+arr[high]+arr[i]==k){
            return true;
        }
        else if(arr[low]+arr[high]+arr[i]>k){
            high--;
        }
        else{
            low++;
        }
    }
    return false;
}

//void function to print the result
void accept (int arr[],int k,int i){
    while(arr[i]>k){
        i--;
    }
    int a=0;
    while(i-a>=2){
        if(check(arr,k,i-a)){
            cout<<"YES";
            return;
        }
        a++;
    }
    cout<<"NO";
    return;
}

int main(){
    //k is the key which is required to find the sum
    //n is the size of the array
    int k,n;
    cout<<"Enter the value of k ";
    cin>>k;
    cout<<"Enter the value of n ";
    cin>>n;
    cout<<endl;
    int arr[n];
    //input of array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //input of array done
    //sorting
    int counter = 1;
    while (counter < n-1){
        for(int i=0;i<n-counter;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i+1],arr[i]);
            }
        }
        counter++;
    }
    //not we have a sorted array
    //calling the accept
    accept(arr,k,n-1);
    return 0;
}