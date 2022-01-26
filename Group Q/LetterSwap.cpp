#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int i=0;
    int j=0;
    while(i<s.length()){
        if(s[i+1]!=' '){
            while((s[j+1]!=' ') && ( (j+1)!=s.length() ) ){
                j++;
            }
            swap(s[i],s[j]);
            i=j+2;
            j+=2;
        }
        else{
            i+=2;
            j+=2;
        }
    }

    cout<<s;
    return 0;
}