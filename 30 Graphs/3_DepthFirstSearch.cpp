#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vb vis(N,false);
vvi adj(N);

void dfsPreOrder(int i){
    // preorder
    vis[i] = true;
    cout<<i<<" ";
    vi :: iterator j;
    for(j = adj[i].begin() ; j != adj[i].end() ; j++){
        if(vis[*j] == false){
            vis[*j] = true;
            dfsPreOrder(*j);
        }
    }
    // cout<<i<<""; // post order
}

int main(){
    int n,m;
    cin>>n>>m;


    int x,y;
    rep(i,0,m){
        cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    int start; // starting node
    cin>>start;

    dfsPreOrder(start);

    return 0;
}

// 7 8
// 1 4 1 3 4 2 4 8 4 5 4 7 3 8 3 7
// 1