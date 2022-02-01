// https://www.spoj.com/problems/EXPEDI/
#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vpi;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

int minStops1(int n,vpi a,int l,int p){
    sort(a.begin(),a.end(),[&](pair<int,int> &a,pair<int,int> &b){
        if(a.ff == b.ff)
            return a.ss > b.ss;
        return a.ff > b.ff;
    });

    int i=0,ans=0,q=INT_MIN,t;

    while(i<n){
        if((l-a[i].ff) <= p){
            i++;
            if(((p-(l-a[i].ff)) + a[i].ss) > q){
                q = ((p-(l-a[i].ff)) + a[i].ss);
                t = i;
            }
        }
        else{
            ans++;
            l-=(a[t].ff);
            p = ((p-(l-a[t].ff)) + a[t].ss);
            i=t+1;
        }
    }
    return ans;
}

int minStops2(int n,vpi a,int l,int p){
    rep(i,0,n)a[i].ff = l - a[i].ff;

    sort(a.begin(),a.end());

    int ans = 0;
    int curr = p;
    priority_queue<int,vector<int>> pq;

    rep(i,0,n){
        if(curr>p)
            break;

        while(curr<a[i].ff){
            if(pq.empty()){
                return -1;
            }
            ans ++;
            curr += pq.top();
            pq.pop();
        }
        
        pq.push(a[i].ss);
    }

    while(!pq.empty() and curr < l){
        curr += pq.top();
        pq.pop();
        ans++;
    }

    if(curr < l)return -1;

    return ans;
}

int main(){
    int n;
    cin>>n;
    
    vpi a(n);
    
    rep(i,0,n)cin>>a[i].ff>>a[i].ss;

    int l,p;
    cin>>l>>p;

    cout<<minStops2(n,a,l,p);

    
    return 0;
}

// 5
// 4 3
// 3 5
// 3 6
// 5 8
// 4 7
// 13 10