//Who got max candies
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    int maxNo=INT_MIN;
    for(int i=0;i<5;i++){
        maxNo=max(maxNo,arr[i]);
    }
    cout<<maxNo;
    return 0;
}