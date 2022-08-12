#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef unordered_map<int,int> mi;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vvi adj(N);
vb vis(N,false);

bool isCycle(int i){
    vis[i] = true;

    bool ans = false,flag = false;

    vi :: iterator it;
    for(it = adj[i].begin() ; it != adj[i].end() ; it++){
        if(vis[*it] == false){
            vis[*it] = true;
            flag = true;
            ans = (ans || isCycle(*it));
        }
        else{
            flag = (flag || false);
        }
    }

    if((flag == false) && (adj[i].size()>1))
        return true;
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int start;
    cin>>start;

    if(isCycle(start))
        cout<<"Cycle Exists"<<endl;
    else
        cout<<"Cycle Dosen't Exists"<<endl;

    return 0;
}

// 8 8
// 1 3 1 4 3 9 3 12 3 8 8 5 5 4 4 2
// 2

// 8 7
// 1 3 1 4 3 9 3 12 3 8 8 5 4 2
// 1