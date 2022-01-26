#include<bits/stdc++.h>
using namespace std;

int main(){

    string s = "askkvvnnfjjd";

    for(int i=0; i<s.size()-1; i++){
        if(s[i]==s[i+1]){
            s.erase(i,1);
        }
    }

    cout << s << endl;

    return 0;
}