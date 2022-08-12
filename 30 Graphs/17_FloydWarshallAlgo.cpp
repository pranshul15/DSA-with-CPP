#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define INF (int)1e9
#define rep(i,a,b) for(int i=a;i<b;i++)

void FloydWarshall(vvi &d,int n){
    rep(i,0,n){
        rep(j,0,n){
            if(j==i)
                continue;
            rep(k,0,n){
                if(k==i)
                    continue;
                d[j][k] = min(d[j][k] , d[j][i] + d[i][k]);
            }
        }
    }
}

int main(){
    // cin>>n;
    vvi d = {
        {0,2,-2,INF},
        {5,0,INF,3},
        {INF,INF,0,INF},
        {INF,INF,-1,0}
    };
    int n = d.size();

    FloydWarshall(d,n);

    rep(i,0,n){
        rep(j,0,n){
            if(d[i][j] >= (INF-10000))
                cout<<"I ";
            else
                cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
4
0 2 -2 1e9
5 0 1e9 3
1e9 1e9 0 1e9
1e9 1e9 -1 0
*/ 