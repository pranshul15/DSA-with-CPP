// we have to output elements in decreasing frequency 
// till we reach (k+1)th distinct elements
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpi;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define pb push_back

int main(){
    int n,k;
    cin>>n>>k;

    vi v(n);

    rep(i,0,n)cin>>v[i];

    map<int,int> freq;

    rep(i,0,n){
        int presentSize = freq.size();
        if(freq[v[i]]==0 && presentSize==k)
            break;
        ++freq[v[i]];
    }

    map<int,int> :: iterator it;

    vpi ans(k);

    for(it = freq.begin() ; it != freq.end() ; it++){
        ans.pb({it->ss,it->ff});
    }

    sort(ans.begin(),ans.end(),greater<pii>());

    vpi :: iterator it1;

    for(it1 = ans.begin() ; it1 != ans.end() ; it1++){
        if(it1->ff != 0){
            cout<<it1->ss<<" "<<it1->ff<<endl;
        }
    }

    return 0;
}