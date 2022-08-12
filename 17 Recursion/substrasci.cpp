//program to print substrings and ascii code
#include<bits/stdc++.h>
using namespace std;

void sbsta(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string ros=s.substr(1);
    sbsta(ros,ans);                      //nothing added
    sbsta(ros,ans+ch);                   //first char added
    sbsta(ros,to_string(int(ch)));       //ascii value added 
}

int main(){
    string s;
    cin>>s;
    sbsta(s,"");
    return;
}