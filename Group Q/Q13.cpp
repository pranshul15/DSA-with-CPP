#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string first(string s,int n){
    if(n%2==0){
        return s.substr(0,n/2);
    }
    else{
        return s.substr(0,(n/2)+1);
    }
}

string last(string s,int n){
    return s.substr(n/2);
}

bool lapindrome(string s,int n){
    int sum1=0,sum2=0;
    for(int i=0;i<((n/2)+0.6);i++){
        sum1=sum1+first(s,n)[i];
        sum2=sum2+last(s,n)[i];
    }
    if(sum1==sum2){
        return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the number of words ";
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    
    for(int i=0;i<n;i++){
        if(lapindrome(arr[i],arr[i].size())){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}