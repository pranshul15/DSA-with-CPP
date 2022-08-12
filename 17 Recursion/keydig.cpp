//to write a program such tha it prints all the possible outcomes of the 
//keypad mobile alphabets
#include<bits/stdc++.h>
using namespace std;

string keypadarr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string ros = s.substr(1);
    string a = keypadarr[int(ch-'0')];

    for(int i=0;i<a.length();i++){
        keypad(ros,a[i]+ans);
    }
}

int main(){
    string s;
    cin>>s;


    return 0;
}