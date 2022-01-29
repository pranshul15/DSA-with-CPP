#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef vector<int> vi;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

int mC2(int m){
    return (m*(m-1))/2;
}

int main(){
    int n;
    cin>>n;
    vi v(n);
    
    rep(i,0,n)cin>>v[i];
    
    vi prefix_sum(n);
    prefix_sum[0] = v[0];

    rep(i,1,n)
        prefix_sum[i] = prefix_sum[i-1] + v[i];

    map<int,int> freq;

    rep(i,0,n)
        freq[prefix_sum[i]]++;

    map<int,int> :: iterator it;

    int ans = 0;
    for(it = freq.begin() ; it != freq.end() ; it++){
        
        ans += mC2(it->ss);
        
        if(it->ff == 0)
            ans += it->ss;
    }

    cout<<ans;
    return 0;
}