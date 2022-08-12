#include<bits/stdc++.h>
using namespace std;

class bubble{
    void setDist(){
        dist = (x*x)+(y*y);
    }
public:
    int size;
    int x;
    int y;
    int dist;
    bubble(int size,int x,int y){
        this->size = size;
        this->x = x;
        this->y = y;
        setDist();
    }
};
struct CompareBubble{
    bool operator () (bubble const& b1,bubble const& b2) {
        if(b1.dist!=b2.dist) return b1.dist<b2.dist;
        return b1.size>b2.size;
    }
};

int main(){
    int n;
    cin>>n;
    priority_queue<bubble,vector<bubble>,CompareBubble> pq;
    for(int i=0;i<n;i++){
        int size,x,y;
        cin>>size>>x>>y;
        bubble t(size,x,y);
        pq.push(t);
    }
    while(pq.size()>1){
        bubble b1 = pq.top();
        pq.pop();
        bubble b2 = pq.top();
        pq.pop();
        bubble b3(b1.size+b2.size,b1.x-b2.x,b1.y-b2.y);
        pq.push(b3);
    }
    bubble p = pq.top();
    cout<<p.x<<" "<<p.y<<endl;
    return 0;
}

/*
5
3 4 3
5 2 7
6 4 9
1 3 7
8 1 3
*/