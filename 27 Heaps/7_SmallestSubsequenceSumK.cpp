#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef vector<int> vi;
#define rep(i,a) for(int i=0;i<a;i++)

int main(){
    int n,k;
    cin>>n>>k;
    
    vi v(n);
    
    rep(i,n)
        cin>>v[i];
    
    priority_queue<int,vi> pq;

    rep(i,n)
        pq.push(v[i]);

    int sum=0,cnt=0;

    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
        cnt++;
        if(sum >= k)
            break;
    }

    if(sum < k)
        cout<<"No such subsequence possible";
    else
        cout<<cnt;
    return 0;
}