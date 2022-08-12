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
int n,m;
vi key(N,INT_MAX);
vb mstSet(N,false);
int cost =0;

void Prim_MST(int src){
    key[src] = 0;
    mstSet[src] = true;
    int curr = src;
    int count = 1;

    while(count < n){
        
        // assigning all the adjacent edges their keys
        rep(i,0,adj[curr].size()){
            int next = adj[curr][i].ff; // represents next adjacent edge
            int weight = adj[curr][i].ss; // represents weight with adjacent adge
            if(mstSet[next] == false){   
                key[next] = min(weight,key[next]);
            }
        }

        // finding the smallest weight node
        int nextNode = -1;
        int weight = INT_MAX;
        rep(i,0,N){
            if(mstSet[i] == false){
                if(weight > key[i]){
                    weight = key[i];
                    nextNode = i;
                }
            }
        }

        mstSet[nextNode] = true;
        cost+=weight;
        curr = nextNode;
        count++;
    }
}

int main(){
    cin>>n>>m;

    rep(i,0,m) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    Prim_MST(0);
    cout<<cost<<endl;
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

