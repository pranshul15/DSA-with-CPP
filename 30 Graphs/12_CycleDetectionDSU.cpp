#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vi parent(N);
vi sz(N);

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int u,int v){
    u = find_set(u);
    v = find_set(v);

    if(u != v){
        if(sz[u] < sz[u])
            swap(u,v);

        parent[v] = u;
        sz[u] += sz[v];
    }
}

int main(){
    rep(i,0,N)make_set(i);

    int n,m;cin>>n>>m;

    vector<pair<int,int>> edges(m);
    
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        edges[i] = {u,v};
    }

    bool isCycle = false;

    rep(i,0,m){
        int x = find_set(edges[i].first);
        int y = find_set(edges[i].second);

        if(x==y) {
            isCycle = true;
            break;
        }
        else 
            union_set(x,y);
    }

    if(isCycle)
        cout<<"Cycle is Present"<<endl;
    else
        cout<<"Cycle is Absent"<<endl;
    return 0;
}

/*
5 5
1 2 2 3 3 4 4 5 5 1
*/

/*
5 4
1 2 2 3 3 4 4 5
*/ 