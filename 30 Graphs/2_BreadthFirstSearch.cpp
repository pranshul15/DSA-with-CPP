#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

int main(){
    int n,m;
    cin>>n>>m;

    vvi adj(N);
    vb vis(N,false);

    int x,y;
    rep(i,0,m){
        cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<int> q;

    int start; // starting node
    cin>>start;

    q.push(start);
    vis[start] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";

        vi :: iterator i;
        for(i = adj[curr].begin() ; i != adj[curr].end() ; i++){
            if(vis[*i] == false){
                q.push(*i);
                vis[*i] = true;
            }
        }
    }

    return 0;
}


// 7 8
// 1 4 1 3 4 2 4 8 4 5 4 7 3 8 3 7
// 1