#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unordered_map<int,int> mi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vector<vector<pair<int,int>>> adj(N);
vb mstSet(N,false);
vi key(N,INT_MAX);

void Prim_MST(int src){
    mstSet[src] = true;
    key[src] = 0;

    
}

int main(){
    int n,m;
    cin>>n>>m;

    vi node(n);
    rep(i,0,n) cin>>node[i];

    rep(i,0,m) {
        int u,v,w;
        cin>>u,v,w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    Prim_MST(node[0]);
    return 0;
}