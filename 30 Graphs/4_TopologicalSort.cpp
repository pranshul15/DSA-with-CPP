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
mi indegree;

int main(){
    int n,m;
    cin>>n>>m;


    int u,v;
    rep(i,0,m){
        cin>>u>>v;
        // u -> v
        adj[u].pb(v);
        indegree[u];
        indegree[v]++;
    }

    queue<int> q;
    mi::iterator it;

    for(it = indegree.begin() ; it != indegree.end() ; it++){
        if(it->second == 0){
            q.push(it->first);
            it->second = -1;
        }
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        vi::iterator j;
        for(j = adj[curr].begin() ; j != adj[curr].end() ; j++){
            indegree[*j]--;
            if(indegree[*j]==0){
                indegree[*j]=-1;
                q.push(*j);
            }
        }
    }

    return 0;
}

// 7 7
// 1 4 1 3 4 2 4 5 4 8 3 8 3 7