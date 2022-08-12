#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    
    for(int i=0;i<=s.length();i++){

        if(s[i]==' ')
        {
            int j=i-1;
            while(s[j]!=' ')
            {
                cout<<s[j];
                if(j==0){
                    break;
                }
                j--;
            }
            cout<<" ";
        }

        if(i==s.length())
        {
            int j=i-1;
            while(s[j]!=' ')
            {
                cout<<s[j];
                j--;
            }
        }
    }
    return 0;
}