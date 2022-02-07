// https://cp-algorithms.com/data_structures/disjoint_set_union.html

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define N 1e5 + 2
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

vi parent(N,0);
vi size_set(N,0);

void make_set(int v){
    parent[v] = v;
    size_set[v] = 1;
}

// O(n)
int find_set(int v){
    if(parent[v] == v)
        return v;
    return find_set(parent[v]);
}

// almost O(1)
void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b) {
        if(size_set[a] < size_set[b])
            swap(a,b);

        parent[b] = a;
        size_set[a] += size_set[b];
    }

    return;
}

int main(){
    
    return 0;
}