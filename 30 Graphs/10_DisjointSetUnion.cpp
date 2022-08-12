#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vvi adj(N);
vi parent(N,0);

void make_set(int v){
    parent[v] = v;
}

// O(n)
int find_set(int v){
    if(parent[v] == v)
        return v;
    return find_set(parent[v]);
}

// O(log n)
int find_set_pathCompression(int v){
    if(parent[v] == v)
        return v;
    return parent[v] = find_set_pathCompression(parent[v]);
}

void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b) {
        parent[b] = a;
    }

    return;
}

int main(){
    
    return 0;
}