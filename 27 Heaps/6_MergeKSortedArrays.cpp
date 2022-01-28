#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
#define rep(i,a,b) for(int i=a;i<b;i++) 

int main(){
    int k;
    cin>>k;
    
    vector<vector<int>> a(k);
    // input for all the elements
    rep(i,0,k){
        int num;
        cin>>num;

        rep(j,0,num){
            int input;
            cin>>input;
            a[i].push_back(input);
        }
    }

    // putting elements in min-heap
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    rep(i,0,k){
        rep(j,0,a[i].size()){
            pq.push({a[i][j],i});
        }
    }

    vi ans;
    while(!pq.empty()){
        pii elementToPush = pq.top();
        ans.push_back(elementToPush.first);
        pq.pop();
    }

    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }

    return 0;
}