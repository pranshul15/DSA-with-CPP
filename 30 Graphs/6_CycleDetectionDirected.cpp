#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef unordered_map<int,int> mi;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vvi adj(N);
mi recStack;

bool isCycle(int i){
    
    if(adj[i].size() == 0)
        return false;

    recStack[i] = 1;
    
    bool ans = false;

    vi :: iterator it;
    for(it = adj[i].begin() ; it != adj[i].end() ; it++){
        if(recStack[*it] == 0){
            ans = (ans || isCycle(*it));
        }
        else
            ans = true;
    }

    recStack[i] = 0;

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }

    int start;cin>>start;

    if(isCycle(start))
        cout<<"Graph contains Cycle"<<endl;
    else
        cout<<"Graph does not contains Cycle"<<endl;

    return 0;
}

// 7 7
// 1 5 5 2 2 3 2 8 2 4 4 10 3 1

// 7 6
// 1 5 5 2 2 3 2 8 2 4 4 10