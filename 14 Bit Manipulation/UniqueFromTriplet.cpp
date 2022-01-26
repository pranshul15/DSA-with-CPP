#include<bits/stdc++.h>
using namespace std;

bool GetBit(int n, int pos){
    return ((n & (1<<pos)) != 0);
}

int SetBit(int n,int pos){
    return (n | (1<<pos));
}

int unique(int arr[],int n){
    int result = 0;                       //result variable to return
    for(int i=0; i<64 ; i++){             //basically an array of size 64 from 0 to 63
        int sum =0;                       
        for(int j=0; j<n; j++){
            if(GetBit(arr[j],i)){
                sum++;
            }
        }
        if ((sum % 3) != 0){
            SetBit(result,i);
        }
    }
    return result;
}

int main(){

    int arr[]={1,1,1,2,2,2,3,3,3,4};


    return 0;
}