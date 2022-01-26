#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];

    cin.getline(arr,n);
    cin.ignore();

    int i=0;
    int currLen=0,maxLen=0,initial,finalizer;

    while(1){

        if(arr[i] == ' ' || arr[i] == '\0'){
            if(currLen>maxLen){
                maxLen=currLen;
                initial=i-maxLen;
                finalizer=i-1;
            }
            currLen=0;
        }
        else{
        currLen++;
        }

        if(arr[i] == '\0'){
            break;
        }
        i++;
    }
    cout<<maxLen<<endl;

    for(int i=initial;i<=finalizer;i++){
        cout<<arr[i];
    }

    return 0;
}