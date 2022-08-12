//program to print all possible substrings

#include<bits/stdc++.h>
using namespace std;

void sbst(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch= s[0];
    string ros = s.substr(1);
    sbst(ros,ans);
    sbst(ros,ans+ch);
}

int main(){
    sbst("ABC","");
    return 0;
}