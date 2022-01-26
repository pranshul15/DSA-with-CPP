#include<bits/stdc++.h>
using namespace std;

int main(){

    string s = "asdvnfjkdnc";

    for(int i=0; i<s.size(); i++){
        if(s[i]>='a' && s[i]<='z'){
            s[i] -= 32;
        }
    }

    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    return 0;
}