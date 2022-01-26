//program to give all the permutations of string through recursion

#include<bits/stdc++.h>
using namespace std;

void SPer(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    for(int i=0;i<s.length();i++){
        SPer(ros,ans.insert(i,to_string(ch)));
    }
    
 }

void StrPer(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string ros = s.substr(0,i)+s.substr(i+1);
        StrPer(ros,ch+ans);
    }
}

int main(){
    string s;
    cin>>s;
    StrPer(s,"");
    
    return 0;
}