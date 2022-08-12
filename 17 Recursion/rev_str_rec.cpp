#include<bits/stdc++.h>
using namespace std;

void revstr(string a){
    if(a.length()==0){
        return;
    }
    string ros = a.substr(1);
    revstr(ros);
    cout<<a[0];
} 

int main(){
    string s = "binod";
    revstr(s);
    return 0;
}