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
vb vis(N,false);
vi shortestDist(N,INT_MAX);
int n,m;

void dijkstra(int src){
    shortestDist[src] = 0;
    vis[src] = true;
    int count = 1;
    int curr = src;

    while(count < n){
        // update distances of all the adjacent vertices
        rep(i,0,adj[curr].size()){
            int next = adj[curr][i].ff; // value of adjacent node
            int distance = adj[curr][i].ss; // distance from current to adjacent node

            if(vis[next] == false){
                shortestDist[next] = min(shortestDist[next],shortestDist[curr]+distance);
            }
        }

        // finding the node with smallest distance
        int nextNode = -1;
        int dist = INT_MAX;
        rep(i,0,n){
            if(vis[i] == false){
                if(shortestDist[i] < dist){
                    nextNode = i;
                    dist = shortestDist[i];
                }
            }
        }

        vis[nextNode] = true;
        curr = nextNode;
        count ++;
    }
}

int main(){
    cin>>n>>m;

    rep(i,0,m){
        int u,v,w;

        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    dijkstra(0);
    rep(i,0,n){
        if(shortestDist[i] != 0){
            cout<<i<<" -> "<<shortestDist[i]<<endl;
        }
    }
    return 0;
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 8 2
2 5 4
2 3 7
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/ 