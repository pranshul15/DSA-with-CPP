#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unordered_map<int,int> mi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vvi adj(N);
vi color(N,0);

bool biPartite(int i,int c){
    color[i] = c;

    bool ans = true;

    vi :: iterator it;
    for(it = adj[i].begin() ; it != adj[i].end() ; it++){

        if(color[*it] == 0)
            ans = ans && biPartite(*it,3-c);

        else
            if(color[*it] == c) ans = false;

    }

    return ans;
}   

int main(){
    int n,m;
    cin>>n>>m;

    vi nodes(n);
    vvi components;

    rep(i,0,n)
        cin>>nodes[i];

    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool ans = true;

    for(int i=0;i<nodes.size();i++){
        if(color[nodes[i]]==0){
            ans = ans && biPartite(nodes[i],1);
        }
    }
    
    if(ans)
        cout<<"Given Graph is BiPartite"<<endl;
    else
        cout<<"Given Graph is not BiPartite"<<endl;

    return 0;
}

/*
8 10
1 4 3 2 9 6 8 5
1 6 1 8 4 9 4 8 4 5 3 9 3 6 3 8 2 9 2 8
*/