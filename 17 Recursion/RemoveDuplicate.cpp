#include<bits/stdc++.h>
using namespace std;

void rdup(string s){              //self thought
    if(s.length()==0){
        return;
    }
    
    if(s[0]==s[1]){
        rdup(s.substr(1));
    }
    else{
        cout<<s[0];
        rdup(s.substr(1));
    }
}

string removeDup(string s){         //solution in the video
    if(s.length()==0){
        return "";
    }

    char ch = s[0];

    string ans = removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    
    return ch+ans;
    
}

int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    cout<<s<<endl;
    rdup(s);
    return 0;
}