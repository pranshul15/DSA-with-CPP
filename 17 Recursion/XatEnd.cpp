//given a string program has to move all the x to the end

#include<bits/stdc++.h>
using namespace std;

string x_end(string s){
    if(s.length()==0){
        return "";
    }
    char ch =s[0];
    string ans = x_end(s.substr(1));
    if(ch=='x'){
        return ans+'x';
    }
    return ch+ans;
}

int main(){
    string s;
    cin>>s;
    cout<<x_end(s);
    return 0;
}