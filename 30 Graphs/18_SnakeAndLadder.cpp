#include<bits/stdc++.h>
using namespace std;

int main(){
    int ladders,snakes;
    cin>>ladders;

    map<int,int> lad;
    for(int i=0;i<ladders;i++){
        int u,v;
        cin>>u>>v;
        lad[u] = v;
    }

    cin>>snakes;
    map<int,int> snak;
    for(int i=0;i<snakes;i++){
        int u,v;
        cin>>u>>v;
        snak[u] = v;
    }

    queue<int> q;
    q.push(1);
    bool found = false;
    vector<bool> vis(101,false);
    int moves;

    while(!q.empty() && !found){
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();

            for(int die=1;die<=6;die++){
                if(t+die == 100)
                    found=true;
                if(t+die <=100 && lad[t+die] && !vis[lad[t+die]]){
                    vis[t+die] = true;
                    if(lad[t+die]==100)
                        found=true;
                    q.push(lad[t+die]);
                }
                else if(t+die<=100 && snak[t+die] && !vis[snak[t+die]]){
                    vis[snak[t+die]] = true;
                    if(snak[t+die]==100)
                        found = true;
                    q.push(snak[t+die]);
                }
                else if(t+die<=100 && !lad[t+die] && !snak[t+die] && !vis[t+die]){
                    vis[t+die]=true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }
    if(found)
        cout<<moves<<endl;
    else
        cout<<-1<<endl;
    return 0;
}

/*
2
3 90
56 76
3
99 10
30 20
20 5
*/ 