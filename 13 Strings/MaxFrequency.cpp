#include<bits/stdc++.h>
using namespace std;

int main(){

    string s = "asldnfdibscmdlf";

    int freq[26];

    for(int i=0; i<26; i++){
        freq[i]=0;
    }

    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
    }

    int maxf=0;
    char ans = 'a';

    for(int i=0; i<26; i++){
        if(freq[i]>maxf){
            maxf = max(freq[i],maxf);
            ans += i;
        }
    }

    cout << ans << " " << maxf << endl;

    return 0;
}