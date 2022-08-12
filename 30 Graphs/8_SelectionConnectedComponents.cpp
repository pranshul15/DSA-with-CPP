/* 
    N Friends numbered 0 to N-1
    Choose two friends such that they are not related to each other
    Find number of ways in which 2 person from different groups can be chosen
*/
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
            // cout<<endl;
            components.pb(temp);
        }
    }

    int ans = 0;

    if(components.size() < 2){
        cout<<"Not Possible"<<endl;
    }
    else{
        for(int i=0 ; i<components.size() ; i++){
            for(int j=i+1;j<components.size();j++){
                ans += (components[i].size()*components[j].size());
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

/*
9 6
1 5 2 9 8 4 6 3 7
1 5 5 8 5 9 5 2 4 6 6 3
*/