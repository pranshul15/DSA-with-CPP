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
vb vis(N,false);

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

    queue<int> q;

    cout<<endl;

    vi :: iterator it;
    for(it = nodes.begin() ; it != nodes.end() ; it++){
        if(!vis[*it]){
            // cout<<*it<<endl<<"\t";
            q.push(*it);
            vi temp;

            while(!q.empty()){
                int t = q.front();
                temp.pb(t);
                vis[t] = true;
                q.pop();
                // cout<<t<<" ";

                vi :: iterator j;
                for(j = adj[t].begin() ; j != adj[t].end() ; j++){
                    if(!vis[*j])
                        q.push(*j);
                }
            }
            cout<<endl;
            components.pb(temp);
        }
    }

    vvi :: iterator k;

    for(k = components.begin() ; k != components.end() ; k++){
        vi :: iterator y;
        for(y = k->begin() ; y != k->end() ; y++){
            cout<<*y<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
9 6
1 5 2 9 8 4 6 3 7
1 5 5 8 5 9 5 2 4 6 6 3
*/