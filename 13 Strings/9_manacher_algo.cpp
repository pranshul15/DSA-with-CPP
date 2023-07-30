// Manacher's algorithm is used to find the longest palindromic
// subsequence

#include<bits/stdc++.h>
using namespace std;

class manacher{
public:
    string lps(string &s);
};

string manacher::lps(string &s) {
    int n = s.length();
    int N = 2*n+1;
    char newS[N];

    int i=0;
    newS[i++]='#';

    for(char c:s) {
        newS[i++] = c;
        newS[i++] = '#';
    }

    int center=0, right=0;
    int lps[N];


    for(i=0 ; i<N ; i++) {
        int mirror = 2*center-i;

        if (i < right) {
            lps[i] = min(right-i, lps[mirror]);
        }

        while((i+1+lps[i] < N) && (i-1-lps[i]>=0) && (newS[i+1+lps[i]] == newS[i-1-lps[i]])) {
            lps[i]++;
        }

        if(i+lps[i] > right) {
            center = i;
            right = i+lps[i];
        }

    }

    int max_length = 0;
    int center_index = 0;

    for(i=0 ; i<N ; i++) {
        if (lps[i] > max_length) {
            max_length = lps[i];
            center_index = i;
        }
    }

    int start_index = (center_index - max_length) / 2;

    return s.substr(start_index,max_length);

}

int main() {
    manacher m;
    string s = "aabbaab";
    cout<<m.lps(s);
    return 0;
}