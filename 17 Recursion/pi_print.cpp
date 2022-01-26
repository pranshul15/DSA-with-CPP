#include<bits/stdc++.h>
using namespace std;

void prpi(string s)
{
    if(s.length()==0){      //base condition
        return;
    }

    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        prpi(s.substr(2));
    }
    else{
        cout<<s[0];
        prpi(s.substr(1));
    }
}

int main(){
    string s = "pippxpixpxpi";
    prpi(s);
    return 0;
}