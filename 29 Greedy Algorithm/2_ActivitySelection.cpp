// Given n activities with starting and ending times
// Max activities that can be performed by single person
// one activity at any given time
#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vpi;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second


int main(){
    int n;
    cin>>n;
    vpi activity(n);

    rep(i,0,n)cin>>activity[i].ff>>activity[i].ss;

    sort(activity.begin(),activity.end(),[&](pair<int,int> &a,pair<int,int> &b){
        return a.ss<b.ss;
    });

    int ans = 1,e = activity[0].ss;
    rep(i,1,n){
        if(activity[i].ff >= e){
            ans++;
            e = activity[i].ss;
        }
    }

    cout<<ans<<endl;
    return 0;
}