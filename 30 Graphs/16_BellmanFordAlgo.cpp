#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unordered_map<int,int> mi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define ff first
#define ss second

vector<vector<pair<int,int>>> adj(N);
vi shortestDist(N,INT_MAX);
int n,m;

void BellmanFord(int src){
    shortestDist[src] = 0;

    rep(i,0,n-1){

        rep(j,0,N){

            rep(k,0,adj[j].size()){


                int adjacentNode = adj[j][k].ff;
                int dist = adj[j][k].ss;

                shortestDist[adjacentNode] = min(shortestDist[adjacentNode],shortestDist[j] + dist);
                
            }
        }
    }
}

// Bellman ford algorithm may fail for negative weight cycle
// if the values of shortest distance changes in nth iteration
// means that bellman ford algorithm failed

int main(){
    cin>>n>>m;

    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
    }

    BellmanFord(0);

    rep(i,0,n){
        cout<<i<<" -> "<<shortestDist[i]<<endl;
    }
    return 0;
}

/*
6 9
0 1 6
0 2 4
0 3 5
1 4 -1
2 1 -2
2 4 3
3 2 -2
3 5 -1
4 5 3
*/ 