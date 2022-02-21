/*
You are given a string s consisting of lower case latin letters
('a'-'z') and some '?'
Your task is to find number of subsequences 'abc' in all the strings '?'
should be replaced by {'a','b','c'}
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define ff first
#define ss second
#define N (int)1e3+2
#define INF (int)1e9

int main(){
    int n;cin>>n;
    string s;
    cin>>s;

    vvi dp2(n,vi(4,0));

    if(s[0] == 'a')
        dp2[0][0] = dp2[0][1] = 1;

    else if(s[0] == 'b' || s[0] == 'c')
        dp2[0][0] = 1;

    else if(s[0] == '?'){
        dp2[0][0] = 3;
        dp2[0][1] = 1;
    }

    rep(i,1,n){
        if(s[i] == 'a'){
            dp2[i][0] = dp2[i-1][0];
            dp2[i][1] = dp2[i-1][1] + dp2[i-1][0];
            dp2[i][2] = dp2[i-1][2];
            dp2[i][3] = dp2[i-1][3];
        }

        else if(s[i] == 'b'){
            dp2[i][0] = dp2[i-1][0];
            dp2[i][1] = dp2[i-1][1];
            dp2[i][2] = dp2[i-1][2] + dp2[i-1][1];
            dp2[i][3] = dp2[i-1][3];
        }

        else if(s[i] == 'c'){
            dp2[i][0] = dp2[i-1][0];
            dp2[i][1] = dp2[i-1][1];
            dp2[i][2] = dp2[i-1][2];
            dp2[i][3] = dp2[i-1][3] + dp2[i-1][2];
        }

        else if(s[i] == '?'){
            dp2[i][0] = dp2[i-1][0] * 3;
            dp2[i][1] = (dp2[i-1][1]*3) + dp2[i-1][0];
            dp2[i][2] = (dp2[i-1][2]*3) + dp2[i-1][1];
            dp2[i][3] = (dp2[i-1][3]*3) + dp2[i-1][2];
        }
    }

    cout<<dp2[n-1][3];
    return 0;
}

/*
6
ac?b?c
7
???????
9
cccbbbaaa
5
a???c

*/ 