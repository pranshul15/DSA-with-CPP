//to find sum of all subarrays
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){cin>>array[i];}
    
    for(int i=1;i<n;i++){
        int current =array[i];
        int j=i-1;
        while(array[i]>current && j>=0){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=current;
    }
    return 0;
}