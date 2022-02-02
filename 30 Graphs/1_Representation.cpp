#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,a,b) for(int i=a;i<b;i++)

const int N = 1e5 + 2;

int main(){

    int n,m;
    // number of vertex
    // number of edges
    cin>>n>>m;

    vvi a(n+1,vi(n+1,0));
    vvi b(n+1);

    rep(i,0,m){
        int x,y;
        cin>>x>>y;

        a[x][y] = 1;
        a[y][x] = 1;

        b[x].push_back(y);
        b[y].push_back(x);
    }

    // adjacency matrix
    cout<<"Represenation of Adjancency Matrix"<<endl;
    rep(i,1,n+1){
        rep(j,1,n+1)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\n\n\nRepresentation of Adjecency List"<<endl;
    rep(i,1,n+1){
        int t = b[i].size();
        if(t){
            cout<<i<<" -> ";
            rep(j,0,t)
                cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    // adjacency list



    return 0;
}

// 7 8
// 5 7 5 6 7 1 7 4 7 2 7 3 6 2 6 3