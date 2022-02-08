#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unordered_map<int,int> mi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vi parent(N);
vi sz(N,0);

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

// path compression
int find_set(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int u,int v){
    u = find_set(u);
    v = find_set(v);

    if(u!=v){
        if(sz[u] < sz[v])
            swap(u,v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}
bool detectCycle(int a,int b){
    int x = find_set(a);
    int y = find_set(b);

    if(x == y)
        return true;
    
    return false;
}

int main(){
    rep(i,0,N) make_set(i);

    int n,m;
    cin>>n>>m;

    vi nodes(n);
    rep(i,0,n) cin>>nodes[i];

    vvi edges(m);

    rep(i,0,m){
        int w,u,v;
        cin>>w>>u>>v;
        edges[i] = {w,u,v};
    }

    sort(edges.begin(),edges.end());

    rep(i,0,m){
        int x,y;
        bool isCycle = detectCycle(edges[i][1],edges[i][2]);
        if(!isCycle){
            union_set(edges[i][1],edges[i][2]);
        }
    }

    rep(i,0,n){
        if(sz[nodes[i]] == n){
            rep(j,0,N){
                if(parent[j] == nodes[i])
                    cout<<j<<" ";
            }
            break;
        }
    }
    return 0;
}


/*
9 14
0 1 2 3 4 5 6 7 8
4 0 1
8 0 7
11 1 7
7 7 8
1 7 6
6 6 8
2 2 8
8 1 2
7 2 3
4 2 5
2 6 5
14 3 5
9 3 4
10 5 4
*/ 