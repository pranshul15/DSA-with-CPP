//Palindromes- if we write a word and then again write it with words flipper, if the spelling is same then 
//the given word is Palindrome
//example NITIN
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n+1];
    cin>>arr;

    bool flag=true;
    int i=0;
    while(i<=(n/2)){
        if(arr[i] != arr[n-1-i]){
            flag = false;
            break;
        }
        i++;
    }

    if(flag){
        cout<<"It is Palindromic";
    }
    else{
        cout<<"Non Palindromic";
    }

    return 0;
}