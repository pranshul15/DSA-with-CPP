#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
typedef pair<int,int> pi;
#define PB push_back
#define F first
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define reb(i,a,b) for(int i=a-1;i>=b;i--)

int main(){
    // implementation of maxheap
    priority_queue<int,vector<int>> pq;
    pq.push(3);
    pq.push(5);
    pq.push(2);

    cout<< pq.top() << "\n";

    // implementation of min heap
    priority_queue<int,vector<int>,greater<int>> pqm;
    pqm.push(4);
    pqm.push(2);
    pqm.push(6);
    pqm.push(1);
    cout<< pqm.top() << "\n";

    return 0;
}